import sys

def getIncludeLobColumn(aqplogfilename):
    result_table_name_list = []
    tablename = ""
    f = open(aqplogfilename, 'r')
    while True:
        line = f.readline()
        if line.find("create table") > 0:
            startIdx = line.find("\"")
            endIdx = line[startIdx+1:].find("\"")
            
            if ( startIdx > 0 ) and ( endIdx > 0 ): # create table ddl
                tablename = line[startIdx+1:startIdx+1+endIdx]
                print("tablename: ", tablename)
                
                while True:
                    line = f.readline() 
                    if line.find("CLOB") > 0 or line.find("BLOB") > 0:
                        result_table_name_list.append(tablename)
                    if line.find(']') > 0:
                        break
        if not line: 
            break
    f.close()
    return result_table_name_list

#qplogfilename = ""
args = sys.argv[1:]
qplogfilename = args[0]
inputfilename = args[1]
print("qplogfilename =", qplogfilename)
print("inputfilename =", inputfilename )
print(getIncludeLobColumn(qplogfilename))
# for i in args:
#     qplogfilename = i
#     print(i)