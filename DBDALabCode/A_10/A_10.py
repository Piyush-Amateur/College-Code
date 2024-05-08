import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import plotly.express as px
from sklearn.datasets import load_iris
import warnings


#data = load_iris()
#df = pd.DataFrame()
#df[data['feature_names']] = data['data']
#df['label'] = data['target']


iris  = sns.load_dataset("iris")


iris


iris.shape


iris.columns



iris.head()


iris.tail()


iris.info()


iris.describe()


# Select only the numeric columns for correlation. Exclude categorical data.
numeric_iris = iris.select_dtypes(include=[float, int])
# Compute the correlation matrix
corr_matrix = numeric_iris.corr()


sns.heatmap(corr_matrix, annot=True)
plt.show()


sns.histplot(x=iris["sepal_length"], kde=True)
plt.show()


sns.histplot(x=iris["sepal_width"], kde=True)
plt.show()


sns.histplot(x=iris["petal_length"], kde=True)
plt.show()


sns.histplot(x=iris["petal_width"], kde=True)
plt.show()


sns.boxplot(iris, x="species",y="sepal_length",palette='pastel')


sns.boxplot(iris, x="species",y="sepal_width",palette='pastel')


sns.boxplot(iris, x="species",y="petal_length",palette='pastel')


sns.boxplot(iris, x="species",y="petal_width",palette='pastel')


