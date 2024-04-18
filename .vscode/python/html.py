import re
def striphtml(data):
    p=re.compile(r"<.>")
    return p.sub("",data)