# Project 4 Report

Answer the following prompts directly in this file:
* Information about your dataset (you will be assigned a different grader for this project).

My data set contains one thousand asteroids orbiting the sun in our solar system. They have attributes 
such as ID, SPKID, Name, Full Name, Near Earth Object, Hazardous, Magnitude and Diameter.

* Analyze the data. Graph the number of reads and allocations for each sorting algorithm and look at how the number of reads and allocations grows when the size of the data set grows. Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.

There is a very obvious trend, that the more reads there are for an algorithm, the more allocations 
there will be. In my examples, bubble sort being the most efficient has 1998 reads and 0 allocations, 
where as quick sort is the least efficient has 2004490 reads and 216,646,704 allocations.
Heap sort ends up being a bit more inefficient than bubble with about 6,500 reads and 860,000 allocations, 
and merge even less efficient than that at 30,000 reads and 2,900,000 allocations. When comparing complexities,
Bubble and Quick sorts are O(N^2), where as Heap and Merge are both O(NLogN). However, we see that one of the
O(N^2) algorithms, bubble, is the most efficient, and the other, quick sort, is the least efficient with both 
O(NLogN) algorithms in the middle. This is due to the fact that a data set size of one thousand is small enough
that O(N^2) for bubble sort out performs all the others in the smaller numbers, as it grows very slow at first.

* Look at the output from the stabilityTest function and answer the following questions:
  * How are the names sorted by default?
  
  They are sorted in alphabetical order of their first names.

  * How is the output from the two stable sorting algorithms different from the two unstable ones? Be specific in your answer, and use what you know about how each sorting algorithm works to justify your observations.
  
  The two stable algorithms order the people by both first and last name, with last taking priority. 
  They first get split by last name, put into groups and then get sorted in order by first. In the unstable 
  algorithms, they are just sorted by last, with no attention to the first name order. We know that unstable means
  that the program will mix the order of people to find a final order, whereas in the stable algorithms, they keep
  everything in the same relative order so that the people do not mix.

* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why? 
  
  I would use Heap Sort as it is the most efficient, stable algorithm. It would order people in my contact list first 
  by last name, then by first name making it the easiest and most efficient way to find people, almost like the
  way a dictionary is ordered.

  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?
  
  I would use bubble sort, simply because it is the most efficient, and is able to terminate prematurely, meaning that
  it will not do any un-needed work. It is able to stop automatically if it detects that everything is already in order.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**
