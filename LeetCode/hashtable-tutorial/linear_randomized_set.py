from random import randint


class RandomizedSet:

    def __init__(self):
        self.linear_data = list()
        self.vals_to_idx = dict()

    def insert(self, val: int) -> bool:
        if val not in self.vals_to_idx:
            self.linear_data.append(val)
            self.vals_to_idx[val] = len(self.linear_data) - 1

            return True

        return False

    def remove(self, val: int) -> bool:
        if val in self.vals_to_idx:
            # remove given val from my map
            idx = self.vals_to_idx[val]
            del self.vals_to_idx[val]

            if idx != len(self.linear_data) - 1:
                # get the last element and update its index in the map to be the the deleted value's index
                last_element = self.linear_data[-1]
                self.vals_to_idx[last_element] = idx

                # in linear data, swap values of last element and deleted element
                self.linear_data[-1], self.linear_data[idx] = self.linear_data[idx], self.linear_data[-1]

            # remove the last item, this would be a constant operation
            self.linear_data.pop()

            return True

        return False

    def getRandom(self) -> int:
        idx = randint(0, len(self.linear_data) - 1)

        return self.linear_data[idx]


# Your RandomizedSet object will be instantiated and called as such:
obj = RandomizedSet()

print(obj.remove(0))
print(obj.remove(0))
print(obj.insert(0))
print(obj.getRandom())
print(obj.remove(0))

print(f"{obj.linear_data=}", f"{obj.vals_to_idx=}")

print(obj.insert(0))
