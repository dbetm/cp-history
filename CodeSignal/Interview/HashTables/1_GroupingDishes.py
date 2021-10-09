# https://app.codesignal.com/interview-practice/task/xrFgR63cw7Nch4vXo/description
# Tag(s): Implmentation, hash table

def groupingDishes(dishes):
    ingredients_set = dict()
    grouped_dishes = []

    for dish in dishes:
        for i in range(1, len(dish)):
            if dish[i] in ingredients_set:
                ingredients_set[dish[i]].append(dish[0])
            else:
                ingredients_set[dish[i]] = [dish[0]]

    for x in sorted (ingredients_set.keys()):
        if len(ingredients_set[x]) >= 2:
            grouped_dish = [x]
            ingredients_set[x].sort()
            grouped_dish.extend(ingredients_set[x])

            grouped_dishes.append(grouped_dish)

    return grouped_dishes


if __name__ == '__main__':
    number_dishes = int(input())

    dishes = []

    for i in range(number_dishes):
        dish_name = input()
        numbers_ingredients = int(input())

        dish = [dish_name]
        for j in range(numbers_ingredients):
            ingredient = input()
            dish.append(ingredient)
        dishes.append(dish)

    print(groupingDishes(dishes))
