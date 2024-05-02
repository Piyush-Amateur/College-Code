import re
import random

# A dictionary to handle reflections like "I am" -> "you are"
reflections = {
    "i am": "you are",
    "i was": "you were",
    "i": "you",
    "i'm": "you are",
    "i'd": "you would",
    "i've": "you have",
    "my": "your",
    "you are": "I am",
    "you were": "I was",
    "you": "I",
    "your": "my",
    "yours": "mine",
    "you have": "I have",
}

# Regular expression patterns and responses
pairs = [
    (re.compile(r"my name is (.*)", re.IGNORECASE), ["Hello %s, how are you today?"]),
    (re.compile(r"hi|hey|hello", re.IGNORECASE), ["Hello", "Hey there"]),
    (re.compile(r"what is your name\?", re.IGNORECASE), ["I am a bot created by Piyush Tambe. You can call me Chatbot!"]),
    (re.compile(r"how are you\?", re.IGNORECASE), ["I'm doing good. How about you?"]),
    (re.compile(r"sorry (.*)", re.IGNORECASE), ["It's alright", "It's OK, never mind"]),
    (re.compile(r"i am fine", re.IGNORECASE), ["Great to hear that. How can I help you?"]),
    (re.compile(r"i'm (.*) doing good", re.IGNORECASE), ["Nice to hear that. How can I help you?"]),
    (re.compile(r"(.*) age\?", re.IGNORECASE), ["I'm a computer program, dude. Seriously, you are asking me this?"]),
    (re.compile(r"what (.*) want\ ?", re.IGNORECASE), ["Make me an offer I can't refuse."]),
    (re.compile(r"(.*) created\ ?", re.IGNORECASE), ["Piyush created me using Python's NLTK library.", "Top secret ;)"]),
    (re.compile(r"(.*) (location|city)\ ?", re.IGNORECASE), ["Pune, Maharashtra"]),
    (re.compile(r"how is the weather in (.*)\?", re.IGNORECASE), ["Weather in %s is awesome like always", "Too hot man here in %s", "Too cold man here in %s", "Never even heard about %s"]),
    (re.compile(r"i work in (.*)\?", re.IGNORECASE), ["%s is an Amazing company. I have heard about it. But they are in huge loss these days."]),
    (re.compile(r"(.*)raining in (.*)", re.IGNORECASE), ["No rain since last week here in %s", "Damn, it's raining too much here in %s"]),
    (re.compile(r"how (.*) health(.*)", re.IGNORECASE), ["I'm a computer program, so I'm always healthy."]),
    (re.compile(r"(.*) (sports|game)\ ?", re.IGNORECASE), ["I'm a very big fan of Football."]),
    (re.compile(r"who (.*) sportsperson \?", re.IGNORECASE), ["Messi", "Ronaldo", "Rooney"]),
    (re.compile(r"who (.*) (moviestar|actor)\?", re.IGNORECASE), ["Brad Pitt"]),
    (re.compile(r"i am looking for online guides and courses to learn data science, can you suggest\?", re.IGNORECASE), ["Crazy_Tech has many great articles with each step explanation along with code, you can explore"]),
    (re.compile(r"quit", re.IGNORECASE), ["Bye, take care. See you soon :)", "It was nice talking to you. See you soon :)"]),
]

def chat():
    print("Hi! I am a chatbot created by Piyush for your service.")
    while True:
        user_input = input("You: ")
        if user_input.lower() == "quit":
            print("Chatbot: Bye! Take care. See you soon :)")
            break
        else:
            responded = False
            for pattern, responses in pairs:
                match = pattern.match(user_input)
                if match:
                    response = random.choice(responses)
                    # If response contains a placeholder for substitution, we substitute the captured group(s).
                    if "%" in response:
                        response = response % match.groups()
                    print("Chatbot:", response)
                    responded = True
                    break
            if not responded:
                print("Chatbot: Sorry, I didn't understand that.")

if __name__ == "__main__":
    chat()
