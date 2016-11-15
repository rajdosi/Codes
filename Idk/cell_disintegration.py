import sys as xyz

disappearing_nodes_to_coordinates_map = {}

def get_obid(p):
	x=1
	obid=[]
	i = 0 
	while (True):
		if (p[i]!=0):
			break
		obid.append(x)
		x=x+1
		i=i+1

	while (i < len(p)-1):
		if(p[i]==" " and obid[-1]!=" "):
			obid.append(" ")
		elif(p[i]==p[i+1]):
			while(True):
				obid.append(x)
				x=x+1
				if(p[i]!=p[i+1]):									
					break				
				i=i+1
		i=i+1 	
		
	return obid

def get_mp(p):
	mp = []
	x = 1
	i = 0
	while(True):
		if (p[i]!=0):
			break
		mp.append(x)
		x=x+1
		i=i+1

	prev_frame = 0
	cur_frame = 0
	while (i < len(p)-1):
		 
		if(p[i]==" "):
			prev_frame = cur_frame
			cur_frame = i + 1
			mp.append(" ")	
		elif (p[i]==p[i+1]):
			while(True):
				mp.append(x)
				x=x+1
				if(p[i]!=p[i+1]):					
					break				
				i=i+1			
		elif(p[i]!=p[i+1]):		
			mp.append(mp[prev_frame + p[i] - 1])	
		i = i + 1
	return mp

def validation_for_old_node():

	return True;

def similarity_check_for_two_nodes(n1_xcord, n1_ycord, n2_xcord, n2_ycord):


	return True;

def get_first_occurence_map(mp):
	first_occurence_map = {}
	i = 0
	while (i<len(mp)):
		if (mp[i] != " "):
			if (mp[i] not in first_occurence_map ):
				first_occurence_map[mp[i]] = i;			
		i = i + 1;  

	return first_occurence_map

def get_pid(mp,p):
	pid = []
	mark = {}
	mark = set()

	i = 0
	while (True):
		if (mp[i] == " "):
			break
		pid.append(0)
		mark.add(mp[i])
		i = i + 1

	prev_frame = 0
	cur_frame = 0
	while (i < len(mp)):
		if (mp[i] == " "):
			prev_frame = cur_frame
			cur_frame = i + 1
			if (pid[-1] != " "):
				pid.append(" ")

		elif(mp[i] not in mark):
			mark.add(mp[i])
			pid.append(mp[prev_frame + p[i] - 1])
		
		i = i + 1

	return pid
	

def get_life(mp,obid):
	life = [0] * (len(obid) - obid.count(" "))
	i = 0
	while (i<len(mp)):
		if (mp[i] != " "):
			life[int(mp[i])-1] = life[int(mp[i])-1] + 1
		i = i+1

	return life 

im = 	 [1,1, 2,2, 3,3, 4,4,4]
ob = 	 [1,2, 1,2, 1,2, 1,2,3]
p =  	 [0,0, 1,2, 1,1, 1,2,2]
cell_x = [10,90, 20,85, 22,24, 22,23,84]
cell_y = [10,90, 20,90, 20,21, 22,23,91]

# im = [1,1,2,2,2,3,3,3,3,3,4,4,4,4,4]
# ob = [1,2,1,2,3,1,2,3,4,5,1,2,3,4,5]
# p = [0,0,1,1,2,1,1,2,3,3,1,2,3,4,5]

'''ims =  raw_input('Enter im')
obs = raw_input('Enter ob')
ps = raw_input('Enter p')
cell_xs = row_input('Enter cell_x')
cell_ys = row_input('Enter cell_y')
for s in ims:
	im.append(s)
for s in obs:
	ob.append(s)
for s in ps:
	p.append(s)
for s in cell_xs:
	cell_x.append(s)
for s in cell_ys:
	cell_y.append(s)
'''

im_temp = []
ob_temp = []
p_temp = []
cell_x_temp = []
cell_y_temp = []

'''im_temp.append(im[0])
ob_temp.append(ob[0])
p_temp.append(p[0])
cell_x_temp(cell_x[0])
cell_x_temp(cell_y[0])
'''

for i in range(0,len(im)-1):
	if(im[i]!=im[i+1]):
		im_temp.append(im[i])
		im_temp.append(" ")

		ob_temp.append(ob[i])
		ob_temp.append(" ")

		p_temp.append(p[i])
		p_temp.append(" ")

		cell_x_temp.append(cell_x[i])
		cell_x_temp.append(" ")

		cell_y_temp.append(cell_y[i])
		cell_y_temp.append(" ")
	else:	
		im_temp.append(im[i])
		ob_temp.append(ob[i])
		p_temp.append(p[i])
		cell_x_temp.append(cell_x[i])
		cell_y_temp.append(cell_y[i])


im_temp.append(im[i+1])
ob_temp.append(ob[i+1])
p_temp.append(p[i+1])
cell_x_temp.append(cell_x[i+1])
cell_y_temp.append(cell_y[i+1])

p_temp.append(" ")

im = im_temp
ob = ob_temp
p = p_temp
cell_x = cell_x_temp
cell_y = cell_y_temp

mp = get_mp(p)
print "MP : ", mp

obid = get_obid(p)
print "OBID : ", obid

pid = get_pid(mp,p)
print "PID : ", pid

life = get_life(mp,obid)
print "LIFE : ", life