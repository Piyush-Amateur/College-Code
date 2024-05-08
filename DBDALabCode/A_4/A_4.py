import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
#from sklearn.datasets import load_boston
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, mean_absolute_error
from sklearn.preprocessing import StandardScaler
import warnings
warnings.filterwarnings("ignore")
# %matplotlib inline


df = pd.read_csv('train.csv')

#boston = load_boston()
#boston.keys()

#x = pd.DataFrame(boston.data, columns=boston.feature_names)
#y = pd.DataFrame(boston.target, columns=['MEDV'])

x = df.drop("medv",axis = 1)


y = df.drop(["ID","crim","zn","indus","chas","nox","rm","age","dis","rad","tax","ptratio","black","lstat"],axis = 1)


x


y


x.shape , y.shape


x.info()


x.describe()


y.info()


y.describe()


x.isnull().sum()


y.isnull().sum()


df1 = x 
df1["target"]=y
df1.head()


plt.figure(figsize=(15,10))
sns.heatmap(df1.corr(), annot=True)
plt.show()


df1 = df1[['rm', 'lstat', 'target']]


sns.pairplot(df1)
plt.show()


x = df1[['rm', 'lstat']]
y = df1['target']


scaler = StandardScaler()



x = scaler.fit_transform(x)


x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, shuffle=True)


x_train.shape, x_test.shape, y_train.shape, y_test.shape


model = LinearRegression(n_jobs=-1)



model.fit(x_train, y_train)


y_pred = model.predict(x_test)


mean_absolute_error(y_test, y_pred)


mean_squared_error(y_test, y_pred)


sns.regplot(x= y_test,y=  y_pred, color='red')
plt.show()


