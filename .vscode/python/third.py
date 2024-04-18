import torch
from transformers import BertTokenizer, BertForQuestionAnswering
import spacy
from collections import defaultdict
import fitz  # PyMuPDF
import speech_recognition as sr

class ChatGPT:
    def __init__(self):
        self.tokenizer = BertTokenizer.from_pretrained('bert-large-uncased-whole-word-masking-finetuned-squad')
        self.model = BertForQuestionAnswering.from_pretrained('bert-large-uncased-whole-word-masking-finetuned-squad')
        self.nlp = spacy.load("en_core_web_sm")
        self.memory = defaultdict(str)
        self.disease_medicine_mapping = defaultdict(str)
        self.text = ""

    def extract_text_from_pdf(self, pdf_path):
        text = ""
        with fitz.open(pdf_path) as doc:
            for page in doc:
                text += page.get_text()
        return text

    def extract_disease_and_medicine(self, text):
        doc = self.nlp(text)
        diseases = []
        medicines = []
        for entity in doc.ents:
            if entity.label_ == 'DISEASE':
                diseases.append(entity.text)
            elif entity.label_ == 'MEDICINE':
                medicines.append(entity.text)
        return diseases, medicines

    def answer_question(self, question, context):
        input_ids = self.tokenizer.encode(question, context)
        tokens = self.tokenizer.convert_ids_to_tokens(input_ids)
        max_len = self.tokenizer.max_model_input_sizes['bert-large-uncased']
        if len(input_ids) > max_len:
            input_ids = input_ids[:max_len]
            tokens = tokens[:max_len]
        input_ids = torch.tensor([input_ids])
        with torch.no_grad():
            outputs = self.model(input_ids)
            start_scores = outputs.start_logits
            end_scores = outputs.end_logits
        answer_start = torch.argmax(start_scores)
        answer_end = torch.argmax(end_scores) + 1
        answer = self.tokenizer.convert_tokens_to_string(tokens[answer_start:answer_end])
        return answer

    def provide_text(self, text):
        self.text = text
        diseases, medicines = self.extract_disease_and_medicine(text)
        for disease, medicine in zip(diseases, medicines):
            self.disease_medicine_mapping[disease] = medicine
        print("Disease-Medicine Mapping:", dict(self.disease_medicine_mapping))

    def provide_pdf(self, pdf_path):
        self.text = self.extract_text_from_pdf(pdf_path)
        print("Text extracted from PDF:", self.text)
        diseases, medicines = self.extract_disease_and_medicine(self.text)
        for disease, medicine in zip(diseases, medicines):
            self.disease_medicine_mapping[disease] = medicine
        print("Disease-Medicine Mapping:", dict(self.disease_medicine_mapping))

    def ask_question(self, question):
        if not self.disease_medicine_mapping:
            print("Please provide text or PDF with disease and medicine information first.")
            return
        answer = self.answer_question(question, self.text)
        return answer

    def ask_question_via_voice(self):
        recognizer = sr.Recognizer()
        with sr.Microphone() as source:
            print("Speak your question:")
            audio = recognizer.listen(source)
        try:
            question = recognizer.recognize_google(audio)
            print("Question:", question)
            if not self.disease_medicine_mapping:
                print("Please provide text or PDF with disease and medicine information first.")
                return
            answer = self.answer_question(question, self.text)
            return answer
        except sr.UnknownValueError:
            print("Sorry, could not understand audio.")
        except sr.RequestError as e:
            print("Could not request results; {0}".format(e))

    def start_chat(self):
        while True:
            user_input = input("Enter 'text' to provide text, 'pdf' to provide a PDF file, 'question' to ask a question, 'voice' to ask a question via voice, or 'exit' to quit: ")

            if user_input.lower() == 'text':
                text = input("Enter the text: ")
                self.provide_text(text)
            elif user_input.lower() == 'pdf':
                pdf_path = input("Enter the path to the PDF file: ")
                self.provide_pdf(pdf_path)
            elif user_input.lower() == 'question':
                question = input("Ask a question: ")
                answer = self.ask_question(question)
                print("Answer:", answer)
            elif user_input.lower() == 'voice':
                answer = self.ask_question_via_voice()
                print("Answer:", answer)
            elif user_input.lower() == 'exit':
                break
            else:
                print("Invalid input. Please try again.")

if __name__ == "__main__":
    chatbot = ChatGPT()
    chatbot.start_chat()
