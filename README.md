# Descrição do projeto

Este projeto propõe um sistema automatizado e inteligente para captação, armazenamento e utilização da água da chuva na irrigação de forma sustentável. A placa principal utilizada é a ESP8266, responsável pelo controle de toda a automação. Ela se conecta via Wi-Fi a uma rede local, permitindo o monitoramento remoto e o envio de notificações através do Telegram, utilizando o protocolo MQTT com integração ao message broker HiveMQ.

Para integrar sensores e atuadores, é utilizada uma protoboard de 400 pontos, facilitando a prototipagem e a conexão entre os componentes eletrônicos.

O sistema é composto pelos seguintes módulos e funcionalidades:

Sensor de Nível de Água: utilizado para monitorar o volume armazenado no reservatório de água da chuva. Quando o nível atinge a capacidade máxima, o sistema desativa automaticamente a bomba de captação para evitar transbordamentos.

Sensor de Umidade do Solo: responsável por medir a umidade na região irrigada. Quando a umidade atinge um nível abaixo do ideal, o sistema ativa a bomba de irrigação, utilizando a água captada da chuva.

Display LCD 16x2: exibe informações relevantes como o nível da água no reservatório e o status da irrigação (ativado ou desativado). Também poderá apresentar mensagens de alerta em caso de falhas.

Botões Auxiliares: permitem ao usuário administrador configurar parâmetros como o limite mínimo de umidade para iniciar a irrigação, ou forçar manualmente a ativação/desativação do sistema.

Buzzer Passivo 5V e LED Indicador: emitem sinais sonoros e visuais para indicar eventos importantes, como a ativação da irrigação ou alertas de nível baixo de água.

A comunicação remota é realizada através do Telegram Bot, permitindo que o usuário receba notificações instantâneas, tais como:

"Sistema iniciou a irrigação automaticamente às 08:00."

"Reservatório atingiu nível máximo de água."

"Falha na bomba de irrigação detectada."

Além disso, o usuário pode enviar comandos via Telegram para consultar o status do sistema ou forçar a irrigação.

Implementações futuras podem incluir o uso de um Sensor de Chuva, para inibir a irrigação quando estiver chovendo, e um Sensor de Fluxo de Água, para monitorar a quantidade efetiva de água utilizada, promovendo ainda mais eficiência no reaproveitamento dos recursos hídricos.

Este sistema visa promover a economia de água potável e estimular práticas de irrigação sustentáveis, aliando tecnologia IoT e automação residencial.


# Como executar o projeto
1- Acesse Wowki

2- Realize o upload do arquivo "wifi-scan.ino", "diagram.json", "libraries.txt"
