import nltk
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity

# Step 1: Preprocess the text
def preprocess_text(text):
    sentences = nltk.sent_tokenize(text)
    words = [nltk.word_tokenize(sentence) for sentence in sentences]
    words = [nltk.pos_tag(word) for word in words]
    return words

# Step 2: Create a TF-IDF vectorizer
def create_tfidf_vectorizer(texts):
    vectorizer = TfidfVectorizer()
    tfidf_matrix = vectorizer.fit_transform(texts)
    return vectorizer, tfidf_matrix

# Step 3: Find the most similar sentence to the question
def find_most_similar_sentence(question, texts, vectorizer, tfidf_matrix):
    question_vector = vectorizer.transform([question])
    similarities = cosine_similarity(question_vector, tfidf_matrix)
    most_similar_index = similarities.argmax()
    return texts[most_similar_index]

# Step 4: Example usage
def main():
    text = input("Enter the text: ")
    processed_text = preprocess_text(text)
    vectorizer, tfidf_matrix = create_tfidf_vectorizer(text)
    
    while True:
        question = input("Ask a question (type 'exit' to quit): ")
        if question.lower() == 'exit':
            break
        else:
            most_similar_sentence = find_most_similar_sentence(question, processed_text, vectorizer, tfidf_matrix)
            print("Answer:", most_similar_sentence)

if __name__ == "__main__":
    main()