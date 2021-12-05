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
## PCB

Foi montado o circuito com os componentes a serem utilizados e para posteriormente fazer o designer e confecção da placa de circuito impesso. O esquemático do circuito se encontra [aqui](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/CIRCUITO%20E%20PINAGEM.pdf), enquanto o esquema criado e aplicado a placa se encontra [aqui](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/tree/main/PDFS).

<div align="center">
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/PCB(1).jpg" height="361" width="415" />
</div>

----------------------------
## Programação
A programação foi criada na IDE própria do arduino. Ela pode ser vista [aqui](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Programacao_final_2019/Programacao_final_2019.ino). O controle do sistema feito com o arduino em conjunto com o módulo bluetooth, foi idealizado para que as informações fossem apresentadas no app android para smartphone. A utilização do app Blynk fez com que fosse necessário a modificação da programação, visto que o projeto foi feito por etapas e cada etapa foi sendo feito testes com cada um dos sensores e módulos, e para fazer a integração das etapas para serem utilizadas no app era preciso modificar a maneira como a função "void loop()" era utilizada.

----------------------------
## App
O aplicativo utilizado foi o Blynk, mais informações sobre o app podem ser vistas no [site do app](https://blynk.io/). O app foi desenvolvido para exibir o nível de água atual no reservatório, a vazão total registra em litros, o consumo de água baseado na vazão e registrado ao longo do tempo. Ainda no app é possível ligar e desligar a válvula e a bomba de forma "manual", pois o sistema liga e desliga a bomba automaticamente a depender do nível de água atual. Mas caso o usuário necessite desligar a bomba antes de encher o reservatório ou ligar a bomba para encher o reservatório antes de chegar no nível mínimo basta fazer isso através do app. A válvula também é controlada pelo usuário, mas pode ser controlada automaticamente utilizando o "Modo Sleep", que consiste em definir um horário para desligar a válvula, fechando a saída de água do reservatório, e religar novamente após um período de tempo. Esse modo pode ser utilizado para a os dias úteis e tem o auxílio do módulo RTC que registra a data e hora.

<div align="center">
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/App.jpg" height="320" />
<img src="https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/app2.png" height="320" />
</div>

----------------------------
## Testes
Foram realizados diversos testes com os sensores e módulos. Após a confecção da placa e soldagem dos componentes foram feitos testes do protótipo. Um dos testes realizados pode ser visto no vídeo gravado que pode ser acessado clicando na imagem abaixo.

[![](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/teste.png)](https://drive.google.com/file/d/1vLdgxC94QNj52IpdSHeC1SSGb2XNO46e/view?usp=sharing)

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

Outras imagens podem ser vistas [aqui](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/tree/main/Imagens). Também foi gravado um vídeo mostrando o resultado do protótipo final em funcionamento que pode ser visto clicando na imagem abaixo.

[![](https://github.com/luizgmartins/Projeto-Controle-Automatico-de-Reservatorio/blob/main/Imagens/prototipo.png)](https://drive.google.com/file/d/1FAYSTIJthaAiTjAwnbXQABfiS1m8jAsw/view?usp=sharing)

----------------------------
## Observações

* Em alguns momentos a conexão com o módulo bluetooth apresentaram algumas falhas. Desde demora na conexão através do app até um certo delay de algumas funções do app. Isso pode ter sido atribuído ao app que possuia na época um sistema BETA para o módulo bluetooth ou até mesmo a utilização do sensor de fluxo que necessitava do uso de um pino de interrupção do arduino. No caso o sistema poderia estar demorando um pouco para envio de informações para o app. Como em grande parte dos testes o sistema não apresentou falhas não foram feitas mudanças.
* A válvula solenoide esquenta muito quando energizada, pois a bobina aquece quando ligado por um certo período de tempo. Como o sistema é um protótipo não foram feitas mudanças.
* O sensor de fluxo não distingue se está passando água ou ar no sistema. Isso poderia ser um problema em caso de falta de água, pois uma torneira poderia estar puxando ar através da tubulação e fazendo com que o sensor contasse a passagem do ar como consumo de água. Como não foram feitos testes com o protótipo completo sem a utilização de água no reservatório não foram feitas mudanças.
* Era possível utilizar o app Blynk para gerar notificações no smartphone, mas não chegou a ser implementado no projeto. A ideia seria criar alertas para excesso do consumo de água, falta de água ou problemas no sistema como falha no funcionamento da bomba.
* O app funciona com o sistema ligado a um servidor online ou um servidor local. No caso do servidor online é possivel ter acesso ao sistema através do smartphone em qualquer lugar, já o servidor local (que foi utilizado no projeto) poderia ser acessado somente nos smartphones com acesso na mesma rede do servidor. O servidor local foi criado no notebook pessoal para o projeto. Porém, a utilização do módulo bluetooth faz com que o sistema necessite que algum smartphone esteja conecta a ele, pois o sistema inicia quando é feita a conexão. Isso poderia trazer problemas para o funcionamento do sistema quando o smartphone não estivesse por perto, então a melhor forma seria utilizar algum módulo wifi ou ESP para conectar o sistema a alguma rede e evitar esse problema. Um outro problema no uso do servidor local seria a necessidade de um computador ligado para que o sistema pudesse funcionar, mas o servidor local poderia ser utilizados somentes em casos que não fosse possível o acesso através da internet.
*  Mas ficam algumas dicas de mudança para projetos futuros: utilizar algum outro app, que indico o MIT App Inventor; utilizar o mesmo app, porém com algum módulo wifi, ethernet ou uma ESP para fazer a conexão do sistema ao invés do módulo bluetooth; trocar a válvula solenoide por algum outro sistema que corte o fluxo de água que possa ser mais eficiente; fazer algum tipo de verificação de uma possível falta de água para desligar a contagem do sensor de fluxo.

----------------------------
## Referências

 - https://www.arduinoecia.com.br/monitore-sua-caixa-dagua-usando-arduino/
 - http://labdegaragem.com/profiles/blogs/tutorial-como-utilizar-o-sensor-de-fluxo-de-agua
 - https://www.filipeflop.com/blog/sensor-ultrassonico-hc-sr04-ao-arduino/
 - https://www.filipeflop.com/blog/relogio-rtc-ds1307-arduino/
 - https://portal.vidadesilicio.com.br/hc-sr04-sensor-ultrassonico/
 - http://blog.fazedores.com/sensor-ultrassonico-com-arduino/
 - http://docs.blynk.cc/

