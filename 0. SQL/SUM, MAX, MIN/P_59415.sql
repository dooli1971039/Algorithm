-- 최댓값 구하기
SELECT MAX(DATETIME) FROM ANIMAL_INS;

-- 위 아래 모두 가능
SELECT DATETIME FROM ANIMAL_INS
ORDER BY DATETIME DESC
LIMIT 1;