pip install nltk


import nltk
nltk.download('punkt')


from nltk import word_tokenize, sent_tokenize
sent = "Shishir is Good in coding . Pratik is bad in coding"
print(word_tokenize(sent))
print(sent_tokenize(sent))


from nltk.corpus import stopwords
import nltk
nltk.download('stopwords')
stop_words = stopwords.words('english')
print(stop_words)


token = word_tokenize(sent)
cleaned_token = []
for word in token:
 if word not in stop_words:
    cleaned_token.append(word)

print("This is the unclean version : ",token)
print("This is the cleaned version : ",cleaned_token)


words = [cleaned_token.lower() for cleaned_token in cleaned_token if cleaned_token.isalpha()]


print(words)


from nltk.stem import PorterStemmer
stemmer = PorterStemmer()
port_stemmer_output = [stemmer.stem(words) for words in words]
print(port_stemmer_output)


from nltk.stem import WordNetLemmatizer
nltk.download('wordnet')
lemmatizer = WordNetLemmatizer()
lemmatizer_output = [lemmatizer.lemmatize(words) for words in words]
print(lemmatizer_output)


from nltk import pos_tag
import nltk
nltk.download('averaged_perceptron_tagger')
token = word_tokenize(sent)
cleaned_token = []
for word in token:
 if word not in stop_words:
    cleaned_token.append(word)
tagged = pos_tag(cleaned_token)
print(tagged)


from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import pandas as pd


docs = [ "Sachin is considered to be one of the greatest cricket players",
 "Federer is considered one of the greatest tennis players",
 "Nadal is considered one of the greatest tennis players",
 "Virat is the captain of the Indian cricket team"]


 vectorizer = TfidfVectorizer(analyzer = "word", norm = None , use_idf = True , smooth_idf=True)
Mat = vectorizer.fit(docs)
print(Mat.vocabulary_)



tfidfMat = vectorizer.fit_transform(docs)


print(tfidfMat)


features_names = vectorizer.get_feature_names_out()
print(features_names)


dense = tfidfMat.todense()
denselist = dense.tolist()
df = pd.DataFrame(denselist , columns = features_names)


df


docList = ['Doc 1','Doc 2','Doc 3','Doc 4']
skDocsIfIdfdf = pd.DataFrame(tfidfMat.todense(),index = sorted(docList), columns=features_names)
print(skDocsIfIdfdf)



csim = cosine_similarity(tfidfMat,tfidfMat)


csimDf = pd.DataFrame(csim,index=sorted(docList),columns=sorted(docList))




print(csimDf)