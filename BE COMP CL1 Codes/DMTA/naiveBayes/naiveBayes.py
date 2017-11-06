import MySQLdb

connection = MySQLdb.connect(host="localhost",user="root", passwd="student123", db="dataset")
cursor = connection.cursor()

query = ("SELECT count(buys_computer) FROM dataset;")
cursor.execute(query)
total = cursor.fetchone()[0]

print "Input Dataset is: "
query = ("SELECT * FROM dataset;")
cursor.execute(query)
for i in range(0, total):
	dataset = cursor.fetchone()
	print dataset


query = ("SELECT count(buys_computer) FROM dataset where buys_computer='yes';")
cursor.execute(query)
yes = cursor.fetchone()[0]
pYes = float(yes) / total

query = ("SELECT count(buys_computer) FROM dataset where buys_computer='no';")
cursor.execute(query)
no = cursor.fetchone()[0]
pNo = float(no) / total


print "\nEnter the new sample X"
age = raw_input("Age 'youth','middle_aged','senior': ")
income = raw_input("Income 'low','medium','high': ")
student = raw_input("Student 'yes', 'no': ")
credit_rating = raw_input("Credit Rating 'fair', 'excellent': ")

query = ("SELECT count(age) FROM dataset where age='"+age+"' and buys_computer='yes';")
cursor.execute(query)
ageYes = cursor.fetchone()[0]
ageYes = float(ageYes) / yes

query = ("SELECT count(age) FROM dataset where age='"+age+"' and buys_computer='no';")
cursor.execute(query)
ageNo = cursor.fetchone()[0]
ageNo = float(ageNo) / no

query = ("SELECT count(income) FROM dataset where income='"+income+"' and buys_computer='yes';")
cursor.execute(query)
incomeYes = cursor.fetchone()[0]
incomeYes = float(incomeYes) / yes

query = ("SELECT count(income) FROM dataset where income='"+income+"' and buys_computer='no';")
cursor.execute(query)
incomeNo = cursor.fetchone()[0]
incomeNo = float(incomeNo) / no

query = ("SELECT count(student) FROM dataset where student='"+student+"' and buys_computer='yes';")
cursor.execute(query)
studentYes = cursor.fetchone()[0]
studentYes = float(studentYes) / yes

query = ("SELECT count(student) FROM dataset where student='"+student+"' and buys_computer='no';")
cursor.execute(query)
studentNo = cursor.fetchone()[0]
studentNo = float(studentNo) / no

query = ("SELECT count(credit_rating) FROM dataset where credit_rating='"+credit_rating+"' and buys_computer='yes';")
cursor.execute(query)
creditYes = cursor.fetchone()[0]
creditYes = float(creditYes) / yes

query = ("SELECT count(credit_rating) FROM dataset where credit_rating='"+credit_rating+"' and buys_computer='no';")
cursor.execute(query)
creditNo = cursor.fetchone()[0]
creditNo = float(creditNo) / no

print "\nX = <", age,",", income,",", student,",", credit_rating,">\n"

print "P(X|yes) = ", ageYes, " * ", incomeYes, " * ",studentYes," * ",creditYes
pXyes = ageYes * incomeYes * studentYes * creditYes
print "P(X|yes) = ", pXyes

print "\nP(X|no) = ", ageNo, " * ", incomeNo, " * ",studentNo," * ",creditNo
pXno = ageNo * incomeNo * studentNo * creditNo
print "P(X|no) = ", pXno

print "\nP(X|yes) * P(yes) = ", pXyes, " * ", pYes
pXyes = pXyes * pYes
print "P(X|yes) * P(yes) = ", pXyes

print "\nP(X|no) * P(no) = ", pXno, " * ", pNo
pXno = pXno * pNo
print "P(X|no) * P(no) = ", pXno

if(pXyes > pXno):
	print "\nBuys_Computer = 'yes'"
else:
	print "\nBuys_Computer = 'no'"
	
cursor.close()
connection.close()
