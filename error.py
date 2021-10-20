num=-23
try:
    if(num<0):
        raise RuntimeError()
except:
    print("Error ignored")
    pass
