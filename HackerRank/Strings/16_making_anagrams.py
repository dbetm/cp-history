# https://www.hackerrank.com/challenges/making-anagrams/problem
# tag(s): strings, implementation

def create_map(s: str) -> dict:
    map = dict()

    for c in s:
        if c not in map:
            map[c] = 1
        else:
            map[c] += 1

    return map


def get_min_deletions(s1_map: dict, s2_map: dict) -> int:
    total_deletions = 0

    for s1_key, value in s1_map.items():
        if s1_key not in s2_map:
            total_deletions += value
        else:
            total_deletions += abs(value - s2_map[s1_key])
            del s2_map[s1_key]

    total_deletions += sum(s2_map.values())

    return total_deletions



if __name__ == "__main__":
    s1 = input()
    s2 = input()

    print(get_min_deletions(create_map(s1), create_map(s2)))