CREATE TABLE ks.tbl_cnt (pk int PRIMARY KEY, c counter);

-- insert some values
UPDATE ks.tbl_cnt SET c = c+1 WHERE pk = 1;
UPDATE ks.tbl_cnt SET c = c+2 WHERE pk = 2;
UPDATE ks.tbl_cnt SET c = c+3 WHERE pk = 3;
UPDATE ks.tbl_cnt SET c = c+4 WHERE pk = 4;

-- test various filtering options on counter column
SELECT pk, c FROM ks.tbl_cnt WHERE c < 3 ALLOW FILTERING;
SELECT pk, c FROM ks.tbl_cnt WHERE c <= 3 ALLOW FILTERING;
SELECT pk, c FROM ks.tbl_cnt WHERE c > 2 AND pk = 4 ALLOW FILTERING;
SELECT pk, c FROM ks.tbl_cnt WHERE c >= 3 and pk = 3 ALLOW FILTERING;
SELECT pk, c FROM ks.tbl_cnt WHERE c in (2,3) ALLOW FILTERING;
SELECT pk, c FROM ks.tbl_cnt WHERE c = 0 ALLOW FILTERING;
