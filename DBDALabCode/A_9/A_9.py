import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
#import plotly.express as px
import seaborn as sns



titanic = sns.load_dataset("titanic")


titanic


titanic.head()


titanic.tail()


titanic.info()



titanic.describe()


titanic.isna().sum()


titanic["age"] = titanic["age"].fillna(titanic["age"].mean())


titanic.drop('deck',axis = 1 , inplace = True)


titanic.shape


titanic.isna().sum()


#px.box(titanic["sex"], titanic["age"], color=titanic["survived"])


#plt.figure(figsize=(10,7))
box = sns.boxplot(x=titanic["sex"],y= titanic["age"], hue=titanic["survived"])
plt.show()





