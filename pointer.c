# take full name as input
name = input("enter full name")
#split name into parts
parts=name.split()
#short from
short_name=parts[0][0]+"."+parts[-1]
print("short name:",short_name)