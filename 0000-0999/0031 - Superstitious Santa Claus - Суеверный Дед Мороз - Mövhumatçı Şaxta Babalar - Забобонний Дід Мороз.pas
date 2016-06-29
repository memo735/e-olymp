const rik:array[1..12] of integer=(13, 44, 72, 103, 133, 164, 194, 225, 256, 286, 317, 347);
      rik_v:array[1..12] of integer=(13, 44, 73, 104, 134, 165, 195, 226, 257, 287, 318, 348);
      n_y:array[1920..2050] of integer=(5, 7, 1, 2, 3, 5, 6, 7, 1, 3, 4, 5, 6, 1, 2, 3, 4, 6, 7, 1, 2, 4, 5, 6, 7, 2, 3, 4, 5, 7, 1, 2, 3, 5, 6, 7, 1, 3, 4, 5,
                                        6, 1, 2, 3, 4, 6, 7, 1, 2, 4, 5, 6, 7, 2, 3, 4, 5, 7, 1, 2, 3, 5, 6, 7, 1, 3, 4, 5, 6, 1, 2, 3, 4, 6, 7, 1, 2, 4, 5, 6,
                                        7, 2, 3, 4, 5, 7, 1, 2, 3, 5, 6, 7, 1, 3, 4, 5, 6, 1, 2, 3, 4, 6, 7, 1, 2, 4, 5, 6, 7, 2, 3, 4, 5, 7, 1, 2, 3, 5, 6, 7,
                                        1, 3, 4, 5, 6, 1, 2, 3, 4, 6, 7);
var k, i, j, t, rez, st, fin:longint;

begin
  readln (k);
  rez:=0;
  for t:=1 to k do
    begin
      readln (st, fin);
        for i:=st to fin do
          begin
            if i mod 4 = 0 then
              begin
                for j:=1 to 12 do
                  if (rik_v[j]+n_y[i]-1) mod 7 = 6 then inc (rez)
              end
            else
              begin
                for j:=1 to 12 do
                  if (rik[j]+n_y[i]-1) mod 7 = 6 then inc (rez)
              end;
          end;
    end;
  writeln (rez);
end.
