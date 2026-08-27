## FLUXOGRAMA DE FUNCIONAMENTO DO APP
---
```mermaid
flowchart TD
    A([Inicio / Loop ESP32]) --> B[Leitura dos Sensores:\nDHT22, MQ-135 e Boia]
    
    B --> C{Temperatura > 28°C\nOU Umidade < 50%?}
    
    C -- SIM --> D[1. Liga Nebulização/Ventilador\n2. Envia Alerta no Telegram]
    C -- NÃO --> E[Desliga Relés de Climatização]
    
    D --> F{Nível do Bebedouro BAIXO\nOU Amônia > Limite Crítico?}
    E --> F
    
    F -- SIM --> G[Envia Alerta Urgente de Manejo\npara o Técnico Marcos]
    F -- NÃO --> H[Manter Operação Normal]
    
    G --> I[Aguarda 30 segundos]
    H --> I
    
    I --> A
