# solved
# tags: greedy, implementation, simulation


def validStartingCity0(distances, fuel, mpg):
    # it's wrong for all cases
    num_cities = len(distances)

    if num_cities == 1:
        return 0

    acc_fuel = 0
    max_delta = 0
    chosen_city_idx = 0

    for i in range(0, num_cities):
        current_fuel = (mpg * fuel[i]) - distances[i] + acc_fuel
        delta = current_fuel - acc_fuel
        acc_fuel = current_fuel

        print(f"{delta = }")

        if delta > max_delta:
            chosen_city_idx = i
            max_delta = delta

    return chosen_city_idx


def validStartingCity(distances, fuel, mpg):
    """My solution
    Time: O(n^2)
    Space: O(1)
    """
    num_cities = len(distances)
    ans = 0

    for idx in range(0, num_cities):
        acc_fuel = 0
        print("starting at city #", idx)
        has_negative_fuel = False
        for tmp_jdx in range(idx, idx + num_cities):
            jdx = tmp_jdx % num_cities

            current_fuel = (mpg * fuel[jdx]) - distances[jdx] + acc_fuel
            delta = current_fuel - acc_fuel
            acc_fuel = current_fuel

            if current_fuel < 0:
                has_negative_fuel = True
                break

            print(f"{current_fuel=},", f"{delta=}", f"{distances[jdx]=}")
        
        if not has_negative_fuel:
            ans = idx
            break

        print("-"*31)

    return ans


def validStartingCity2(distances, fuel, mpg):
    """proposal
    Time: O(n)
    Space: O(1)

    Notice that it exists the exact enough amount of gas to cover the total distance,
    so, we need to start at the city where when entering to it the amount of fuel is the minimum

    the change in amount of fuel for each city is constant, not matter where we start
    """
    amount_of_miles_of_gas = 0
    min_miles_of_gas = 0 # at city 0 we don't have fuel
    city_with_less_gas = 0
    n = len(distances)

    for i in range(1, n+1):
        amount_of_miles_of_gas += (mpg*fuel[i-1]) - distances[i-1]

        print(f"{amount_of_miles_of_gas=}", f"{i%n=}")

        if amount_of_miles_of_gas < min_miles_of_gas:
            min_miles_of_gas = amount_of_miles_of_gas
            city_with_less_gas = i % n

    return city_with_less_gas


if __name__ == "__main__":
    distances = list(map(int, input().split()))
    fuel = list(map(int, input().split()))
    mpg = int(input())

    print(validStartingCity2(distances, fuel, mpg))
    #print(validStartingCity(distances, fuel, mpg))

