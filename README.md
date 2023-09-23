# Bucket-Sorting

We suppose that the positive or null data are written in decimal writing with at most k digits, in other words that the data are less than 10 to the kth power. We use a table, called "bucket" table, indexed by 0, 1, ..., 9. The table is called bucket. The buckets are: bucket[0], ..., bucket[9]. Each of the bucket is a structure containing two pointers intended to contain the addresses of the beginning and the end of a chained list of integers, a list which will be said to be "contained" by the corresponding bucket. The algorithm proceeds as follows:

- We chain the data: let L be the obtained list.

- For i which varies from 1 to k :

- We initialize all the bucket addresses to NULL.

- We take one by one the nodes of L. For each node m :

- We note n the data contained in the node m

- We note num the ith digit of n from the right (for example, if i is for example, if i is 1, num is the units digit of n)

- We chain the node m at the end of the chained list contained by bucket[num]. We update accordingly the two pointers of baquet[num].

- We reconstitute a list L by chaining "end to end" the contents of baquet[0], then baquet[1], ..., then baquet[9].

This was developed in C language.
