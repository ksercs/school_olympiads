ype mas = array [-1000..1000] of char;
     matr = array [-1000..1000] of mas;
var n, m, i, j : longint;
    k : longint;
    a : matr;
    f1, f2 : text;
procedure min(k : longint);
var i, j : longint;
begin
   for i := 2 to 1 + (k div 2) do
      for j := 1 to i do
         a[i - j + 1, j] := 'C';
   for j := m - 1 downto m - (k - k div 2) do
      for i := n downto n - m + 1 - j - 1  do
         a[i, j + n - i] := 'C';
   for i := 1 to n do
      for j := 1 to m do
         if a[i, j] <> 'C' then a[i, j] := '.';
end;
     
begin
   assign(f1, 'cordon.in');
   assign(f2, 'cordon.out');
   reset(f1);
   rewrite(f2);
   readln(f1, n, m, k);
   if n + m - 3 < k then writeln(f2, 'NO')
   else
   begin
      writeln(f2, 'YES');
      if n = 1 then
      begin
         write(f2, '.');
         for i := 1 to k do
            write(f2, 'C');
         for i := k + 2 to m do
            write(f2, '.');
      end;
      if m = 1 then
      begin
         writeln(f2, '.');
         for i := 1 to k do
            writeln(f2, 'C');
         for i := k + 2 to n do
            writeln(f2, '.');
      end;
      if (n > 1) and (m > 1) then
      begin
         min(k);
         for i := 1 to n do
         begin
            for j := 1 to m do
               write(f2, a[i, j]);
            writeln(f2);
         end;
      end;
   end;
   close(f1);
   close(f2);
end.