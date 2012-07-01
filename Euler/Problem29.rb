#!/usr/bin/ruby

array = []
2.upto(100) do |a|
    2.upto(100) do |b|
        array.push(a ** b)
    end
end
puts array.uniq.size
