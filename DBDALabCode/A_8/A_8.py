import pandas as pd
import numpy as np 
import seaborn as sns
import matplotlib.pyplot as plt


titanic = sns.load_dataset("titanic")

titanic

titanic.shape

titanic.head()

titanic.tail()

titanic.info()

titanic.describe()

titanic.isna().sum()

titanic.columns

titanic["age"]=titanic["age"].fillna(titanic["age"].mean())

titanic.isna().sum()

titanic.columns

titanic.columns


titanic.drop('deck',axis =1 , inplace = True)

titanic

titanic.shape

titanic["sex"].value_counts()

titanic["fare"].value_counts()

titanic["embarked"].value_counts()

def fun1(value):
    if (value == "male"):
        return 1
    else:
        return 0

titanic["sex"] = titanic["sex"].apply(fun1)

titanic

titanic.isna().sum()

titanic

titanic['embarked'] = titanic['embarked'].fillna(titanic['embarked'].mode()[0])

titanic.isna().sum()

titanic['embark_town'] = titanic['embark_town'].fillna(titanic['embark_town'].mode()[0])

corr = titanic.select_dtypes(include=['float64', 'int64']).corr()

# Create a mask using numpy's triu function
mask = np.triu(np.ones_like(corr, dtype=bool))


plt.figure(figsize=(10,8))
sns.heatmap(corr, annot=True , vmin = -1 , vmax = 1 , center =0  )
#sns.heatmap(corr, annot=True , vmin = -1 , vmax = 1 , center =0 ,mask = mask )
plt.show()


sns.countplot(x=titanic["alive"])
plt.show()


sns.countplot(x=titanic["pclass"], hue = titanic["survived"])
plt.show()

sns.countplot(x=titanic["sex"], hue=titanic["survived"], palette="Accent")
#plt.show()

sns.countplot(x=titanic["embarked"], hue=titanic["survived"])
plt.show()

sns.histplot(titanic["fare"])
plt.show()

