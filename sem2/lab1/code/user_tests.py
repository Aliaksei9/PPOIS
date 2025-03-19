import unittest
from user import *
class UserMethodsTets(unittest.TestCase):
    def setUp(self):
        self.system=System({"C":100000},0)
        self.user=User(self.system)
    def test_creation(self):
        self.user.create_object(r"C\WALLPAPER")
        self.user.create_object(r"C\WALLPAPER\WALLPAPERIN")
        source=self.system.disks[0].folders[0]
        self.assertTrue(source.folder_search(r"WALLPAPERIN"))       
    def test_delition(self):
        initial_number=len(self.system.disks[0].folders)
        self.user.create_object(r"C\DeleteTest")
        self.user.delete_object(r"C\DeleteTest")
        self.assertEqual(initial_number, len(self.system.disks[0].folders))
    def test_copying(self):
        self.user.create_object(r"C\CopyingTest")
        self.user.copying(r"C\CopyingTest", r"C\CopyingTest2")
        self.assertTrue(self.system.disks[0].folder_search("CopyingTest2"))
    def test_moving(self):
        self.user.create_object(r"C\MovingTest")
        self.user.moving(r"C\MovingTest", r"C\MovingTest2")
        self.assertTrue(self.system.disks[0].folder_search("MovingTest2"))      
        self.assertFalse(self.system.disks[0].folder_search("MovingTest"))
    def test_zip_unzip(self):
        self.user.create_object(r"C\ZIPTEST")
        self.system.disks[0].folder_search("ZIPTEST").add(File("vidio", "mp4", 200))
        initial_memmory_consumption=self.system.disks[0].folder_search("ZIPTEST")._memmory_consumption
        self.user.archiving(r"C\ZIPTEST")
        self.assertEqual(initial_memmory_consumption-self.system.disks[0].folder_search("ZIPTEST")._memmory_consumption, 600)
        self.user.unzipping(r"C\ZIPTEST")
        self.assertEqual(initial_memmory_consumption-self.system.disks[0].folder_search("ZIPTEST")._memmory_consumption, 0)
    def test_errors(self):
        with self.assertRaises(ValueError):
            self.user.create_object(r"C\ValueError\ValueError")
        with self.assertRaises(ValueError):
            self.user.create_object("k;ljlkhnlkihnhp;jp;oj") 
if __name__ == '__main__':  
    unittest.main()
