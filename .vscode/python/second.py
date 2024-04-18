import torch
from transformers import BertTokenizer, BertForQuestionAnswering
import spacy
from collections import defaultdict
import fitz  # PyMuPDF
import speech_recognition as sr

# Load pre-trained model tokenizer and model
tokenizer = BertTokenizer.from_pretrained('bert-large-uncased-whole-word-masking-finetuned-squad')
model = BertForQuestionAnswering.from_pretrained('bert-large-uncased-whole-word-masking-finetuned-squad')

# Load SpaCy NER model
nlp = spacy.load("en_core_web_sm")

# Dictionary to store previously answered questions and their contexts
memory = defaultdict(str)
disease_medicine_mapping = defaultdict(str)

def extract_text_from_pdf(pdf_path):
    """Extract text from a PDF file."""
    text = ""
    with fitz.open(pdf_path) as doc:
        for page in doc:
            text += page.get_text()
    return text

def extract_disease_and_medicine(text):
    """Extract diseases and medicines from text using SpaCy NER."""
    doc = nlp(text)
    diseases = []
    medicines = []
    for entity in doc.ents:
        if entity.label_ == 'DISEASE':
            diseases.append(entity.text)
        elif entity.label_ == 'MEDICINE':
            medicines.append(entity.text)
    return diseases, medicines

def answer_question(question, context):
    """Answer a question based on the given context using the BERT model."""
    # Tokenize input text
    input_ids = tokenizer.encode(question, context)
    tokens = tokenizer.convert_ids_to_tokens(input_ids)

    # Ensure input length does not exceed maximum
    max_len = tokenizer.max_model_input_sizes['bert-large-uncased']
    if len(input_ids) > max_len:
        input_ids = input_ids[:max_len]
        tokens = tokens[:max_len]

    # Convert inputs to PyTorch tensors
    input_ids = torch.tensor([input_ids])
    
    # Obtain the answer from the model
    with torch.no_grad():
        outputs = model(input_ids)
        start_scores = outputs.start_logits
        end_scores = outputs.end_logits

    # Find the most probable answer
    answer_start = torch.argmax(start_scores)
    answer_end = torch.argmax(end_scores) + 1
    answer = tokenizer.convert_tokens_to_string(tokens[answer_start:answer_end])

    return answer

def main():
    """Main function to interact with the user."""
    while True:
        user_input = input("Enter 'text' to provide text, 'pdf' to provide a PDF file, 'question' to ask a question, 'voice' to ask a question via voice, or 'exit' to quit: ")
        
        if user_input.lower() == 'text':
            text = input("Enter the text: ")
            diseases, medicines = extract_disease_and_medicine(text)
            for disease, medicine in zip(diseases, medicines):
                disease_medicine_mapping[disease] = medicine
            print("Disease-Medicine Mapping:", dict(disease_medicine_mapping))
        elif user_input.lower() == 'pdf':
            pdf_path = input("Enter the path to the PDF file: ")
            text = extract_text_from_pdf(pdf_path)
            print("Text extracted from PDF:", text)
            diseases, medicines = extract_disease_and_medicine(text)
            for disease, medicine in zip(diseases, medicines):
                disease_medicine_mapping[disease] = medicine
            print("Disease-Medicine Mapping:", dict(disease_medicine_mapping))
        elif user_input.lower() == 'question':
            question = input("Ask a question: ")
            if not disease_medicine_mapping:
                print("Please provide text or PDF with disease and medicine information first.")
                continue
            answer = answer_question(question, text)
            print("Answer:", answer)
        elif user_input.lower() == 'voice':
            recognizer = sr.Recognizer()
            with sr.Microphone() as source:
                print("Speak your question:")
                audio = recognizer.listen(source)
            try:
                question = recognizer.recognize_google(audio)
                print("Question:", question)
                if not disease_medicine_mapping:
                    print("Please provide text or PDF with disease and medicine information first.")
                    continue
                answer = answer_question(question, text)
                print("Answer:", answer)
            except sr.UnknownValueError:
                print("Sorry, could not understand audio.")
            except sr.RequestError as e:
                print("Could not request results; {0}".format(e))
        elif user_input.lower() == 'exit':
            break
        else:
            print("Invalid input. Please try again.")

if __name__ == "__main__":
    main()
