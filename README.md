# 2-cell-active-BMS-IITRMS
The multicell battery cell balancer is a key component in a high performance battery management system (BMS) for series-connected Li-Ion cells.The function of the balancer is to efficiently transfer charge to/from a given out-of-balance cell in the stack from/to a larger group of neighboring cells (which includes that individual cell) in order to bring that cell into voltage or capacity balance with its neighboring cells.
High Efficiency Bidirectional Active Charge Balancer 
 2-cell Prototype


 
Contents
1. list of figures
2. Device Overview
3. Components
4. Simulation
5. hardware Design
6. Testing and Verification
List of figures
figure-1 - theoritical circuit of a 2 cell charge balancer
figure-2 - charging and discharging characterstics of both the windings
figure-3 - Simulation Schematic of the circuit
figure-4 - Simulation results showing current in primary and secondary windings
figure-5 - Picture of completed 2 cell charge balancer
Device Overview:- 
The multicell battery cell balancer is a key component in a high performance battery management system (BMS) for series-connected Li-Ion cells.The function of the balancer is to efficiently transfer charge to/from a given out-of-balance cell in the stack from/to a larger group of neighboring cells (which includes that individual cell) in order to bring that cell into voltage or capacity balance with its neighboring cells.
Most balancers in use today employ a unidirectional (discharge only) approach. The simplest of these operate by switching in a resistor across the highest voltage cell(s) in the stack (passive balancing). No charge is recovered in this approach, instead it is dissipated as heat in the resistive element. This can be improved by employing an energy storage element (inductive or capacitive) to transfer charge from the highest voltage cell(s) in the stack to other lower voltage cells in the stack (active balancing).
Components :-
The key components of this balancer are-
 LTC3300-1- The LTC3300-1 is a fault-protected controller IC for transformer-based bidirectional active balancing of multicell battery stacks. All associated gate drive circuitry, precision current sensing, fault detection circuitry and a robust serial interface with built-in watchdog timer are integrated.Each LTC3300-1 can balance up to 6 series-connected battery cells with an input common mode voltage up to 36V.
  Transformer- It  acts as the energy transfer inductive element,with inductance value 0.15mHenry and mutual coupling m=1.
Mosfet- Mosfets acts as switching elements in the circuit with operating voltage near 1.8v and operation voltage 40v and current 6A.
Spi Connectors- To communicate with the IC for execution of commands and reading status.
other components include resistors,capacitors and diodes.
The theoritical circuit to explain the working of this prototype  and the charging and discharging processes is given below in figure-1 and figure-2.

              
                              figure-1                                                                                               figure-2
Simulation:-
The initial task was to get a requisite simulation and calculate the resistance and inductance values for various components according to the specifications of the cells and other components. The simulation was done using Matlab and Simulink and the results of the simulation are given below in figure- 3 and figure-4.
 
                                                                                            figure-3
circuit design in simulink.

 
                                                                                            figure-4
resultant simulation.
Hardware Design:-
The simulation was followed by practical circuit designing and PCB designing. Multisim and Ultiboard software were used for circuit and PCB designing. The complete circuit with components placed on the PCB is shown in figure 5.
 
                                                                                         figure-5
Testing and verification:-
The circuit was then completed and then it was tested whether it is working as expected. This was done using an ATMEGA32 controller which sends the command to be executed to the LTC 3300-1 IC and recieves the data to check the status of the circuit.
served as the master in the SPI communication protocol.
