#lang racket

;; NOTE: for this assignment, do not define constants...
;;       it's fine to have "magic numbers" (e.g., 800) in your code


;; (pay-duty1 duration goods alcohol diplomat) determines
;;   if a Canadian needs to pay duty when returning
;;   to Canada based on the duration of their leave (in hours)
;;   the amount of goods they may have purchased (in dollars)
;;   and whether their goods includes any alcohol or they are a diplomat
;; pay-duty1: Int Int Bool Bool -> Bool
;; requires: 0 <= duration, goods

(define (pay-duty1 duration goods alcohol diplomat)
  (cond [diplomat false]
        [(< duration 24) (> goods 0)]
        [(>= duration 48) (> goods 800)]
        [(<= goods 200) alcohol]
        [else true]))


;; see pay-duty1 [no need to duplicate]

(define (pay-duty2 duration goods alcohol diplomat)
  (and (not diplomat)
       (or (and (< duration 24) (> goods 0))
           (and (< duration 48)
                (or (> goods 200) alcohol))
           (> goods 800))))


;; (my-pow n k) calculates n^k
;; my-pow: Int Int -> Int
;; requires: k >= 0

(define (my-pow n k)
  (cond [(zero? k) 1]
        [else (* n (my-pow n (sub1 k)))]))


;; (count-digits n) determines how many digits are in n
;; count-digits: Int -> Int
;; requires: n >= 0

(define (count-digits n)
  (cond [(< n 10) 1]
        [else (+ 1 (count-digits (quotient n 10)))]))


;; (is-prime-core k n) determines if n is prime by checking
;;   if n is divisible by any numbers from k..2
;; is-prime-core: Int Int -> Bool
;; requires: 1 <= k < n

(define (is-prime-core k n)
  (cond [(= k 1) true]
        [(zero? (remainder n k)) false]
        [else (is-prime-core (sub1 k) n)]))


;; (is-prime) determines if n is prime
;; is-prime: Int -> Bool
;; requires: n > 1

(define (is-prime n)
  (is-prime-core (sub1 n) n))


;; (fibonacci-countup f2 f1 k n) finds the n-th fibonacci number
;;   counting up by k, with f2 and f1 representing the numbers
;;   F[k-2] and F[k-1]
;; fibonacci-countup: Int Int Int Int -> Int
;; requries: 0 <= k <= n

(define (fibonacci-countup f2 f1 k n)
  (cond [(= k n) (+ f2 f1)]
        [else (fibonacci-countup f1 (+ f2 f1) (add1 k) n)]))


;; (fibonacci n) finds the n-th fibonacci number
;; fibonacci: Int -> Int
;; requries: 0 <= n < 47

(define (fibonacci n)
  (cond [(< n 2) n]
        [else (fibonacci-countup 0 1 2 n)]))


;; (reverse-digits n) reverses the digits in n
;; reverse-digits: Int -> Int
;; requires: n >= 0
(define (reverse-digits n)
  (cond [(zero? n) 0]
        [else (+ (* (remainder n 10)
                    (my-pow 10 (sub1 (count-digits n))))
                 (reverse-digits (quotient n 10)))]))


;; (median3 a b c) finds the median ("middle") value of a, b, c
;; median3: Int Int Int -> Int

;; You have to write this one on your own in C
;; but you might want to write in Racket first if that's helpful

;; you may use helper function(s) if you wish
;; here are some examples for you:

;; (median 1 5 7) => 5
;; (median 5 1 7) => 5
;; (median 5 5 7) => 5
;; (median 5 5 5) => 5
;; (median -5 7 0) => 0
