library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity counter is
port ( clock : in std_logic;
		 enable : in std_logic;
		 load_n : in std_logic;
		 initial_value : in std_logic_vector (3 downto 0);
		 clear_n : in std_logic;
		 counter_output : out std_logic_vector (3 downto 0));
end entity counter;

architecture Behavioral of counter is
signal counter_signal:std_logic_vector(3 downto 0) :="0000";
begin
process (clock, clear_n)
begin
   if clear_n='0' then
     counter_signal <= (others=>'0');
   elsif (clock'event and clock='1') then
     if load_n = '0' then
     counter_signal <=initial_value;
     else
     if enable ='1' then
     counter_signal <= counter_signal +1;
     else
     counter_signal <= counter_signal;
     end if;
   end if;
   end if;
end process;
counter_output <= counter_signal;
end Behavioral;
