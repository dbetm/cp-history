from typing import Tuple


class MyHashMap:

    def __init__(self):
        self.num_buckets = 100000
        self.data = [-1] * self.num_buckets

    def get_bucket(self, key: int) -> int:
        return key % self.num_buckets

    def __find__(self, bucket: int, key: int) -> Tuple[int]:
        for idx, (key_, value_) in enumerate(self.data[bucket]):
            if key_ == key:
                return (idx, value_)

        return (-1, -1)

    def put(self, key: int, value: int) -> None:
        bucket = self.get_bucket(key)

        if self.data[bucket] == -1:
            self.data[bucket] = [(key, value)]
        else:
            idx, _ = self.__find__(bucket, key)

            if idx == -1:
                # add new key along its value
                self.data[bucket].append((key, value))
            else:
                # update value for existing key
                self.data[bucket][idx] = (key, value)

    def get(self, key: int) -> int:
        bucket = self.get_bucket(key)

        if self.data[bucket] == -1:
            return -1

        return self.__find__(bucket, key)[1]

    def remove(self, key: int) -> None:
        bucket = self.get_bucket(key)

        if self.data[bucket] == -1:
            return

        idx, _ = self.__find__(bucket, key)
        if idx == -1:
            return

        self.data[bucket].pop(idx)


# Your MyHashMap object will be instantiated and called as such:
obj = MyHashMap()
obj.put(1,1)
obj.put(2, 2)
print(f"{obj.get(1)=}")
print(f"{obj.get(3)=}")
obj.put(2, 1)
print(f"{obj.get(2)=}")

breakpoint()

obj.remove(2)
print(f"{obj.get(2)=}")