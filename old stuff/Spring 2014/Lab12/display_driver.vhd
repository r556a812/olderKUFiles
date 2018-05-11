library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity display_driver1 is
    Port ( inputs : in  STD_LOGIC_VECTOR (3 downto 0);
           seg_out : out  STD_LOGIC_VECTOR (6 downto 0));
end display_driver1;

architecture Behavioral of display_driver1 is

begin

with inputs select
seg_out <=
"0001001" when x"0" ,
"0000110" when x"1" ,
"1000111" when x"2" ,
"1000111" when x"3" ,
"1000000" when x"4" ,
"1111111" when others;

end Behavioral;


