# AC-Peltier
## Ar-Condicionado com Pastilhas de Peltier
<img src="https://github.com/lfs676/AC-Peltier/blob/main/data/Prot%C3%B3tipo.jpg?raw=true">
Video de Funcinamento: https://drive.google.com/file/d/1qpd-G8frFJLKZu-qmvOw1Irp_6uU8xF9/view?usp=sharing

<div>
  <div align="justify">
    
## Introdução
O ar-condicionado com pastilhas de Peltier é um tipo de sistema de refrigeração que utiliza pastilhas termoelétricas para transferir calor. As pastilhas de Peltier são dispositivos semicondutores que produzem um gradiente de temperatura quando uma corrente elétrica é aplicada a eles. Quando uma corrente elétrica é aplicada a uma pastilha de Peltier, ela remove calor de uma extremidade da pastilha e libera calor na outra extremidade.

No sistema de ar-condicionado com pastilhas de Peltier, as pastilhas são montadas em um circuito para formar um módulo termoelétrico. Esse módulo é então instalado no interior de uma caixa que é isolada termicamente do ambiente externo. Quando a corrente elétrica é aplicada ao módulo termoelétrico, ele remove o calor da caixa e libera-o no ambiente externo, reduzindo a temperatura interna.

Esse tipo de ar-condicionado tem algumas vantagens em relação aos sistemas convencionais de ar-condicionado, como a simplicidade do sistema, a ausência de fluidos refrigerantes e a alta eficiência em baixas temperaturas. No entanto, ele também tem algumas desvantagens, como a baixa capacidade de refrigeração e a necessidade de uma fonte de energia elétrica constante para funcionar.

### Funcionalidades
- Fácil Instalação e uso
- Controle de por aplicativo Android ou Controle Remoto
- Manutenção Simples
- Baixo Consumo em relação aos Ar-Condicionados convencionais

### Especificações do Projeto
Este Projeto foi construido a partir da montagem de um bloco de 4 pastilhas de peltier (TEC1-12706), tendo o seu consumo em máxima potência em 290W, a alimentação do sistema inteiro é feita através de uma ligação à uma rede elétrica de 127/220V.

### Material Necessário

Placa de Controle
- 1 ATMega 328P (8Mhz Clock Interno)
- 1 CI HT12D
- 1 CI HT12E
- 1 Receptor RF 433Mhz
- 1 Transmissor RF 433MMhz
- 1 Módulo HC-05
- 1 Sensor de Temperatura LM35
- 1 Display LCD 16x2 com I2C
- 2 Transistores IRF640
- 1 Regulador 7805
- 6 Push Buttons
- 3 Resistores 330R
- 2 Resistores 1k
- 1 Resistor 10k
- 1 Resistor 47k
- 1 Resistor 750k
- 2 Capacitore 100nF
- 1 Capacitor 100uF
- 1 Diodo 1N4004
- 2 Barras de Pinos Macho
- 2 Barras de Pinos Fêmea
- 3 Conectores KRE 2 Vias

Protótipo
- 4 Pastilhas de Peltier (TEC1-12706)
- 2 Water Blocks
- 2 Dissipadore de Calor
- 2 Coolers (120mm)
- 1 Cooler de Alta Rotação (200mm) 
- 1 Mangueira de Nível (1m)
- 1 Fonte 12V 30A
- Carcaça com isolação térmica


### Montagem da PCB e Protótipo
- Monte o circuito conforme o esquemático
- Faça a programação do [código](https://github.com/lfs676/Physical-Therapy-Glove/blob/main/Physical%20Therapy%20Glove.ino) no ATMega 328P 
- Na montagem na carcaça, coloque os Coolers de 120mm nas laterais para jogarem Ar para dentro do sistema, e o Cooler de 200mm na parte da frente em cima do bloco de pastilhas para jogar o ar frio para fora. As pastilhas devem ser ligadas em 2 Blocos separados, um em cada dissipador de calor conectados ao Water Block para resfriar.
<img src="https://github.com/lfs676/AC-Peltier/blob/main/data/Montagem.png?raw=true">

    

#
# Esquemático do Projeto
O arquivo do projeto foi construido no software Proteus 8.9, sendo necessário esta versão ou uma superior para abrir o mesmo.
Para baixar o esquemático clique [aqui](https://github.com/lfs676/AC-Peltier/blob/main/AC%20Peltier.pdsprj).<br>
<img src="https://github.com/lfs676/AC-Peltier/blob/main/data/Schematic.png?raw=true">

#
# Layout da Placa de Circuito Impresso
Para baixar o Layout clique [aqui](https://github.com/lfs676/AC-Peltier/blob/main/AC%20Peltier%20Layout.PDF).<br>
<img src="https://github.com/lfs676/AC-Peltier/blob/main/data/Layout.png?raw=true">

#
# Layout em 3D da PCB
<img src="https://github.com/lfs676/AC-Peltier/blob/main/data/3D.png?raw=true">
