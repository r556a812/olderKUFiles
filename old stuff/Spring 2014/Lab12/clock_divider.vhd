library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity clock_divider is
	Port ( clk : in  STD_LOGIC;
			 message_clk : out STD_LOGIC
			 );
end clock_divider;

architecture Behavioral of clock_divider is

signal count : std_logic_vector (25 downto 0);

begin

process(clk)
begin
   if (clk'event and clk='1') then
   count <= count + 1;
   end if;
end process;

message_clk <= count(24);

end Behavioral;

