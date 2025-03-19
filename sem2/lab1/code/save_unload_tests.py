import unittest
from user import *
from save_unload import*
class SaveUnloadTest(unittest.TestCase):
    def setUp(self):
        self.system=System({"C":100000},0)
        self.user=User(self.system)
        self.system.disks[0].add(Folder("TestFolder"))
        self.system.disks[0].folders[0].add(File("image", "jpg", 100))
        self.system.disks[0].folders[0].add(File("text", "txt", "abc"))
        self.system.disks[0].folders[0].add(File("vidio", "mp4", 100))
        self.system.disks[0].memmory=self.system.disks[0].folders[0]._memmory_consumption
        SaveUnload.save("test.pkl",self.system)
    def test_unload(self):
        self.system=SaveUnload.unload("test.pkl")
        self.user=User(self.system)        
        self.assertTrue(self.system.disks[0].folders[0].files[0])   
        self.assertTrue(self.system.disks[0].folders[0].files[1])
        self.assertTrue(self.system.disks[0].folders[0].files[2])   
if __name__ == '__main__':  
    unittest.main()
        