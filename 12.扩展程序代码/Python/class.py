# 定义类及成员变量和函数
class myClass(object):
    def __init__(self,x):
        self.__Value = x;
    def GetValue(self):
        return self.Value

# 定义创建类对象并返回该对象成员变量的函数 
def getClassData():
    newClassObject = myClass(4882)
    return newClassObject.GetValue()


