LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY DFlipFlop IS
    PORT ( Clk, D : IN STD_LOGIC;
           Q         : OUT STD_LOGIC);
END DFlipFlop ;

ARCHITECTURE Structural OF DFlipFlop IS
  SIGNAL R, S, R_g, S_g, Qa, Qb : STD_LOGIC ;
  ATTRIBUTE keep : boolean;
  ATTRIBUTE keep of R_g, S_g, Qa, Qb : SIGNAL IS true;
BEGIN
  S <= D;
  R <= NOT (D);
  R_g <= R NAND Clk;
  S_g <= S NAND Clk;
  Qa <= S_g NAND Qb;
  Qb <= R_g NAND Qa;
  Q <= Qa;
END Structural;