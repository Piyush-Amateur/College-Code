bot_name = "College Buddy"

knowledge_base = {
    "what is your name?": [
        f"My name is {bot_name}! Happy to help you out with your College enquiries!"
    ],
    "hello": [
        f"Hello! My name is {bot_name}. Happy to help you out with your College enquiries!"
    ],
    "what are the best colleges from pune?": [
        "COEP",
        "PICT",
        "VIT",
        "CUMMINS",
        "PCCOE"
    ],
    "which are the best engineering branches?": [
        "Computer Engineering",
        "IT Engineering",
        "ENTC Engineering"
    ],
    "what are the top branch cut-offs for coep?": [
        "Computer Engineering : 99.8 percentile",
        "Does not have IT branch",
        "ENTC Engineering: 99.2 percentile",
    ],
    "what are the top branch cut-offs for pict?": [
        "Computer Engineering : 99.4 percentile",
        "IT Engineering : 98.6 percentile",
        "ENTC Engineering: 97.2 percentile",
    ],
    "what are the top branch cut-offs for vit?": [
        "Computer Engineering : 99.8 percentile",
        "IT Engineering: 97.1 percentile",
        "ENTC Engineering: 96.2 percentile",
    ],
    "what are the top branch cut-offs for cummins?": [
        "Computer Engineering : 99.8 percentile",
        "Does not have IT branch",
        "ENTC Engineering: 99.2",
    ],
    "what are the top branch cut-offs for pccoe?": [
        "Computer Engineering : 99.8 percentile",
        "Does not have IT branch",
        "ENTC Engineering: 99.2",
    ],
    "When do college admissions start?": [
        "Admissions generally start around August",
    ],
}

print("College Enquiry Rule Based Chatbot")

def respond(input_str):
    input_str = input_str.lower()
    if input_str in knowledge_base:
        print(input_str)
        responses = knowledge_base[input_str]
        for response in responses:
            print(response)
    else:
        print(input_str)
        print("Question is not present in the knowledge base!")
        answer = input("Could you please enter the appropriate answer for the question below-\nAnswer: ")
        knowledge_base[input_str] = [answer]
        print("Answer added successfully!")

while True:
    user_input = input("You: ")
    if user_input.lower() == 'quit':
        print("Thank you for using the Chatbot")
        break
    respond(user_input)