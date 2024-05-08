import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
#%matplotlib inline



#df = pd.read_csv("train.csv")
df = sns.load_dataset("titanic")

df.head()

df.tail()


df.columns



df.describe()


df.info()


df.isna().sum()


#converting categorical variable to numerical variable 
def fun1(value):
    if(value == "male"):
        return 1
    elif(value == "female"):
        return 0
    else:
        pass


df["sex"].value_counts()


df["sex"] = df["sex"].apply(fun1)


df.head(10)


df_age_greater_than_25 = df[df["age"] > 25.0]



df_age_greater_than_25.head()



df["age"].value_counts()



# numeric to categorical conversion
def fun3(value):
    if (value < 20):
        return "teenager"
    elif (value >= 20 and value < 40):
        return "young"
    elif (value >= 40 and value < 60):
        return "middle aged"
    elif (value >= 60):
        return "senior citizen"
    else:
        pass


df["age"] = df["age"].apply(fun3)



df


