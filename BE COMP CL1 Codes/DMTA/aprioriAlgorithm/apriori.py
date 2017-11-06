from itertools import combinations
transactions=[]
num_items_per_CsetEntry=1

#-------------------------------------------Accept min_sup,conf and transactions-------------------------------------------------------------------------------------
num_trans=int(raw_input("Enter number of transactions :  "))

for i in range(num_trans):
	transactions.append(list(raw_input("Enter items one by one for  transaction "+str(i)+": ").split()))


min_support=int(raw_input("Enter min support count :  "))
confidence=float(raw_input("Enter confidence percentage :  "))


#-------------------------------------------Generate candidate and pruning sets -------------------------------------------------------------------------------------
itemset=set()

for i in transactions:
	for j in i:
		itemset.add(j)
LastL=[]
LastLCount=[]
while len(itemset)>=num_items_per_CsetEntry:
	candidate_set=list(combinations(itemset,num_items_per_CsetEntry))
	LSet=[]
	LitemCount=[]
	itemset=set()
	print ("The Candidate Set "+str(num_items_per_CsetEntry)+" is ")
	for i in range(len(candidate_set)):
		eachCsetElement=candidate_set[i]
		subtransactions=transactions
		for j in range(len(eachCsetElement)):
			subtransactions=[item for item in subtransactions if eachCsetElement[j] in item]
		
		
		print (eachCsetElement,"\t",len(subtransactions))

			
		
		if len(subtransactions)>=min_support:
			LSet.append(eachCsetElement)
			LitemCount.append(len(subtransactions))
			for pruneelement in eachCsetElement:
				itemset.add(pruneelement)
		
#-----------------------Print pruneSet and Candidate set------------------------------------------------------------------------------------------------------------
	
	if(len(LSet)>0):
		print ("The Pruned Set "+str(num_items_per_CsetEntry)+" is ")
		LastL=LSet
		LastLCount=LitemCount
		for  i in range(len(LSet)):
			print (LSet[i]," \t ",LitemCount[i])
 		num_items_per_CsetEntry=num_items_per_CsetEntry+1
 
#-----------------------Print final LSet-----------------------------------------------------------------------------------------------------------------------------
  	
print ("The final Pruned Set  is "	)

for i in range(len(LastL)):
	print LastL[i]," \t ",LastLCount[i]
print
	
#--------------------------------------------------------Generate Association Rules----------------------------------------------------------------------------------
#print list(combinations(LastL[0],3))
#print len(LastL)
num_items_per_CsetEntry-=1
confidenceItems=[]
realconfidenceItems=[]
confidenceItemsVals=[]
for i in range(len(LastL)):
	st=1
	while st<num_items_per_CsetEntry:
		supporti=LastLCount[i]
		lhs=list(combinations(LastL[i],num_items_per_CsetEntry-st))
		for l in lhs:
			rhs=list(combinations(set(LastL[i]).difference(set(l)),st))
			for r in rhs:
				confidenceItems=transactions
				for LHScombinations in l:
					confidenceItems=[x for x in confidenceItems if LHScombinations in x]
				tempconfi=(((float)(supporti))/len(confidenceItems))*100
				
				if tempconfi>=confidence:
				   realconfidenceItems.append(str(l)+"=>"+str(r))
				   confidenceItemsVals.append("\t"+str(tempconfi))
	        st+=1
				

#---------------------------------------------------------Print association rules------------------------------------------------------------------------------------
for i in range(len(realconfidenceItems)):
	print realconfidenceItems[i],"\t",confidenceItemsVals[i]


