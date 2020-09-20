"""
    You are given a day in the format day/month/year.
    Find what day of the week this date was.
"""

#using a library from python.
import datetime
#get the date as input.
date=str(input())
#create a list of days.
day_name= ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday','Sunday']
#use a function in this library to find the index of weekday using date with formating '%d %m %Y'.
day = datetime.datetime.strptime(date, '%d %m %Y').weekday()
#print the day with the index we found out.
print(day_name[day])
