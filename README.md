# Projeto - Controle automático de reservatório de água

**Descrição**: Projeto de controle automático de reservatório utilizando arduino e módulo bluetooth. Controle de nível de água, vazão de água, entrada e saída de água e monitoramento completo utilizando um app para smartphone. O projeto foi realizado como atividade de estágio do curso Técnico em Eletrônica do Instituto Federal de Alagoas (IFAL).

----------------------------

## Componentes Utilizados
* Arduino Nano -> Utilizada para fazer o controle de todo o sistema.
* Módulo Bluetooth -> Utilizado para conectar o arduino ao smartphone enviando e recebendo comandos e dados.
* Sensor Ultrassônico -> Utilizado para medir o nível de água.
* Sensor de fluxo de água -> Utilizando para medir a vazão de saída de água do reservatório.
* Válvula Solenoide -> Utilizada para controlar a saída de água, interrompendo o fluxo de água de forma manual ou automática.
* Bomba d'água -> Utilizada para levar água até o reservatório.
* Módulo Relé -> Utilizado como intermediário de controle entre o arduino e a bomba e válvula. 
* Módulo RTC (Real Time Clock) -> Utilizado como relógio do sistema para ativar funções de controle automático do sistema de acordo com o dia e hora definidos.
* Fonte ATX -> Utilizada para alimentar a bomba e a válvula.


----------------------------
**PCB**
Foi montado o circuito com os componentes a serem utilizados e para posteriormente fazer o designer e confecção da placa de circuito impesso. O esquemático do circuito se encontra [Aqui](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/CIRCUITO%20E%20PINAGEM.pdf), enquanto o esquema criado e aplicado a placa se encontra [Aqui](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/tree/main/PDFS).

<div align="center">
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/PCB(1).jpg" height="361" width="415" />
</div>

----------------------------
# Programação
A programação foi criada na IDE própria do arduino. Ela pode ser vista [Aqui](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Programacao_final_2019/Programacao_final_2019.ino). O controle do sistema feito com o arduino em conjunto com o módulo bluetooth, foi idealizado para que as informações fossem apresentadas no app android para smartphone. O aplicativo utilizado foi o Blynk, mais informações sobre o app podem ser vistas no [site do app](https://blynk.io/). A utilização do app Blynk fez com que fosse necessário a modificação da programação, visto que o projeto foi feito por etapas e cada etapa foi sendo feito testes com cada um dos sensores e módulos.

----------------------------
**App**
<div align="center">
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/App.jpg" height="320" />
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/app2.png" height="320" />
</div>

----------------------------
# Testes
Foram realizados diversos testes com os sensores e módulos. Após a confecção da placa e soldagem dos componentes foram feitos testes do protótipo. Um dos testes realizados pode ser visto no vídeo gravado e acessado [Aqui](https://drive.google.com/drive/u/0/folders/12Dj7j2PZ2Z237pOC_OY5hMqp01GqWVkK).

[![](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/teste.png)](https://drive.google.com/drive/u/0/folders/12Dj7j2PZ2Z237pOC_OY5hMqp01GqWVkK)

----------------------------
## Imagens

----------------------------
**Placa com componentes**
<div align="center">
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/placa%20final%20(3).jpg" height="454" />
</div>

----------------------------
**Placa no protótipo**
<div align="center">
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/Prototipo%20(2).jpg" height="454" />
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/Prototipo%20(3).jpg" height="300" />
</div>

----------------------------
**Protótipo**
<div align="center">
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/Prototipo%20(1).jpg" height="300" />
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/Prototipo%20(4).jpg" height="300" />
</div>

Outras imagens podem ser vistas [Aqui](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/tree/main/Imagens). Também foi gravado um vídeo mostrando o resultado do protótipo final em funcionamento que pode ser visto [Aqui](https://drive.google.com/drive/u/0/folders/12Dj7j2PZ2Z237pOC_OY5hMqp01GqWVkK).

----------------------------
## Observações



