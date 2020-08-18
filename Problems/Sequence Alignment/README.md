# Sequence Alignment Problem

## Definition

### Alignment of Two Strings
Given two strings of length m and n, a subset A of {0, ..., m} X {0, ..., n} such that 
> for every (i, j) and (u, v), i != u, j != v, and if i < u then j < v.

### Cost of Alignment
Given an alignment A of two strings of length m and n,

> cost(A) = the number of unmatched characters.

In our code, the meaning of unmatched character is that two characters are not equal.

## Problem Description
Given two strings x and y, find the alignment A of x and y with the least cost.
