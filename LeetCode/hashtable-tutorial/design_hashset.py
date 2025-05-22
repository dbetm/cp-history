class MyHashSet:

    def __init__(self):
        self.size = 1000
        self.data = [[]] * self.size

    def get_bucket(self, key: int) -> int:
        return key % self.size

    def add(self, key: int) -> None:
        bucket = self.get_bucket(key)

        if key not in self.data[bucket]:
            self.data[bucket].append(key)

    def remove(self, key: int) -> None:
        bucket = self.get_bucket(key)

        if not self.contains(key):
            return

        self.data[bucket].remove(key)

    def contains(self, key: int) -> bool:
        bucket = self.get_bucket(key)

        if len(self.data[bucket]) == 0:
            return False
        
        try:
            self.data[bucket].index(key)
        except:
            return False

        return True



# Your MyHashSet object will be instantiated and called as such:

obj = MyHashSet()
key = 42
obj.add(key)
obj.add(key)
obj.remove(key)
print(obj.contains(key))