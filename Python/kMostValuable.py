"""
    You are given n transictions and you need to show k companies that have the most valuable stock according to these
    transictions.
    Each transaction has the name of the company, the type (B:Buy and S:Sell), amount traded and price of trade.

    Test Case:
    6 2
    ASYI B 20 8.90
    LSUV B 13 5.60
    ANPFF B 4 8.20
    ASYI S 13 8.80
    ANPFF S 3 0.20
    ASYI B 18 7.30

    Output:
    ANPFF
    ASYI

    Explanation:
    There are 6 operations. And the top 2 items (according to the unit price) has been asked.
    Symbol LSUV has only one operation, so its unit price is 5.60$,
    ASYI has been bought twice and sold once, (20*8.90 + 18*7.30 - 13*8.80) with a total price of 195.
    Totally, 38 lots bought and 13 lots sold. So, 25 lots remained with a total price of 195. Then the unit price is 7.8$.
    ANPFF has been bought once and sold once, (4*8.20 - 3*0.20) with a total price of 32.2.
    Only 1 lot remains, thus the unit price is 32.2$
    Thus, the top two items are ANPFF and ASYI.
"""

#take n and k.
n,k=[int(x) for x in input().split()]
#initialize a dictionary to keep track of companies.
companies={}
#for each transaction
for i in range(n):
    #take company name,type,quatity and price
    name,typ,quant,price=input().split()
    quant=float(quant)
    price=float(price)
    #if selling then make the quantity negative for the company.
    if typ=="S":
        quant*=-1
    #total change is quatity*price
    total=quant*price
    #if this company isn't in the dictionary, then just initialize it with a list of quatitity and total.
    if not name in companies:
        companies[name]=[quant,total]
    else:
        #if we have it in the dictionary add the quatity to the first element in the list and total to the second element.
        companies[name][0]+=quant
        companies[name][1]+=total

#crate a dictionary to keep track of the stock value for company.
stock_value={}

#using a build-in function of companies dictionary, for each element:
for comp,data in companies.items():
  #if the total quantity isn't 0
  if not data[0]==0:
    #the stock value of the company is the total revenue divided by total quantity rounded by 4 digits. 
    stock_value[comp]=round(data[1]/data[0],4)
  else:
    #if the quantity is 0, we have a 0 price because we can't sell nothing.
    stock_value[comp]=0

#sort the new dictionary by the biggest value of stock and then by the name of the company.
stock_value=sorted(stock_value.items(), key=lambda x: (-x[1],x[0]), reverse=False)

i=0
for comp in stock_value:
  #while i<k
  if(i==k):
    break
  #print the company name with highest stock value.
  print(comp[0])
  i+=1