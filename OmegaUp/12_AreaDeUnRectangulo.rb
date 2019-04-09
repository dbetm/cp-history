a = []
a = gets.scan(/\d+/).map(&:to_i)
puts a[0] * a[1]
