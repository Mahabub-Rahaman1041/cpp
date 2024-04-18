import openai

class ChatGPT:
    def __init__(self, api_key):
        openai.api_key = api_key

    def ask_question(self, question, context=None):
        response = openai.Completion.create(
            engine="text-davinci-003",  # You can adjust the engine based on your requirements
            prompt=question,
            max_tokens=50,  # Adjust based on the expected length of the answer
            context=context
        )
        return response.choices[0].text.strip()

    def start_chat(self):
        while True:
            user_input = input("You: ")
            if user_input.lower() == 'exit':
                print("Chat ended.")
                break
            response = self.ask_question(user_input)
            print("Bot:", response)

if __name__ == "__main__":
    api_key = "YOUR_OPENAI_API_KEY"
    chatbot = ChatGPT(api_key)
    chatbot.start_chat()
