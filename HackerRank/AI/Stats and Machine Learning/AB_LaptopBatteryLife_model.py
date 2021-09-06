import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error
import matplotlib.pyplot as plt
# https://www.hackerrank.com/challenges/battery/problem

data = pd.read_csv(filepath_or_buffer='data/AB_training_data.txt')
data = data.sort_values(by='charging_time')

X = data['charging_time']
y = data['battery_duration']
# y.plot.hist()

# Lookint at the graph we can figure that isn't necessary a ML model
plt.plot(X, y)
plt.grid()

X = X.values.reshape(-1, 1)

model = LinearRegression(fit_intercept=True)

model.fit(X, y)

#print(model.coef_.shape)
#print(model.coef_)
#print(model.intercept_.shape)
#print(model.intercept_)

predictions = model.predict(X)
plt.plot(X, predictions)
plt.show()
#my_score = 10.0
#acc_sum = 0.00

#for i, pred in enumerate(predictions):
    #print(pred, y[i])
    #acc_sum += abs(pred - y[i])

#my_score -= acc_sum
#print("My score", my_score)
#print(model.predict([[0.09]]))
