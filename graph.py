import matplotlib.pyplot as plt 
x_value = [0,1,2,3,4,5]
y_value_dt = [0,8.36,1.81,0.086,0.50,-0.129]
y_value_rf = [0,7.65,1.36,0.08,0.27,0.05]
y_value_nb = [0,45.6,18.47,0.46,4.37,-20.9]
y_value_knn = [0,13.10,4.39,0.13,0.919,-1.578]
y_value_lstm = [0,98.67,39.23,0.98,100,-88.539] 
tick_label = ['','rmse','rmrse','mape','r','R^2']

plt.plot(x_value, y_value_dt, label ='Decession Tree',color='green', linewidth = 2, marker='o', markerfacecolor='green', markersize=8) 
plt.plot(x_value, y_value_rf, label ='Random Forest',color='red', linewidth = 2, marker='8', markerfacecolor='red', markersize=8) 
plt.plot(x_value, y_value_nb,label ='Navie Bayes',color='yellow', linewidth = 2, marker='s', markerfacecolor='yellow', markersize=8) 
plt.plot(x_value, y_value_knn, label ='KNNeighbours',color='magenta', linewidth = 2, marker='+', markerfacecolor='magenta', markersize=8) 
plt.plot(x_value, y_value_lstm, label ='LSTM',color='cyan', linewidth = 2, marker='*', markerfacecolor='cyan', markersize=8) 
plt.xlabel('Evaluating metrices') 
plt.xticks(range(len(tick_label)), tick_label, size='small')
plt.ylabel('Respective error') 
plt.title('Comparing all algorithm')
plt.legend()
plt.show()