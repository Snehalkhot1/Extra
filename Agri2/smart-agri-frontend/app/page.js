'use client';

import { useState } from 'react';

const API_BASE = process.env.NEXT_PUBLIC_API_BASE_URL || 'http://localhost:5000';

export default function Home() {
    const [language, setLanguage] = useState('English');
    const [input, setInput] = useState('');
    const [messages, setMessages] = useState([{
        sender: 'bot',
        text: 'Namaste! I am your Smart Agriculture AI assistant. How can I help your farm today?'
    }]);
    const [loading, setLoading] = useState(false);

    const sendMessage = async() => {
        if (!input.trim()) return;
        const userMessage = input.trim();

        setMessages(prev => [...prev, { sender: 'user', text: userMessage }]);
        setInput('');
        setLoading(true);

        try {
            const res = await fetch(`${API_BASE}/api/chat`, {
                method: 'POST',
                headers: { 'Content-Type': 'application/json' },
                body: JSON.stringify({ message: userMessage, language })
            });

            const data = await res.json();
            const reply =
                data.reply ||
                'Sorry, I could not get an answer right now. Please try again later.';

            setMessages(prev => [...prev, { sender: 'bot', text: reply }]);
        } catch (err) {
            console.error(err);
            setMessages(prev => [
                ...prev,
                { sender: 'bot', text: 'Network error. कृपया बाद में पुनः प्रयास करें।' }
            ]);
        } finally {
            setLoading(false);
        }
    };

    const handleKeyPress = e => {
        if (e.key === 'Enter' && !e.shiftKey) {
            e.preventDefault();
            sendMessage();
        }
    };

    const startVoiceInput = () => {
        if (typeof window === 'undefined') return;

        const SpeechRecognition =
            window.SpeechRecognition || window.webkitSpeechRecognition;

        if (!SpeechRecognition) {
            alert('Voice input not supported in this browser.');
            return;
        }

        const recognition = new SpeechRecognition();
        recognition.continuous = false;
        recognition.interimResults = false;

        if (language === 'Hindi') recognition.lang = 'hi-IN';
        else if (language === 'Marathi') recognition.lang = 'mr-IN';
        else recognition.lang = 'en-IN';

        recognition.onresult = event => {
            const transcript = event.results[0][0].transcript;
            setInput(transcript);
        };

        recognition.onerror = event => {
            console.error('Speech recognition error:', event.error);
        };

        recognition.start();
    };

    return ( <
        main className = "page" >
        <
        div className = "container" >
        <
        header className = "header" >
        <
        div >
        <
        h1 > Smart Agriculture AI Assistant < /h1> <
        p > Ask anything about crops, soil, pests, weather, and market. < /p> <
        /div> <
        div className = "language-select" >
        <
        label htmlFor = "language" > Language: < /label> <
        select id = "language"
        value = { language }
        onChange = { e => setLanguage(e.target.value) } >
        <
        option value = "English" > English < /option> <
        option value = "Hindi" > Hindi(हिन्दी) < /option> <
        option value = "Marathi" > Marathi(मराठी) < /option> <
        /select> <
        /div> <
        /header>

        <
        section className = "chat-card" >
        <
        div className = "messages" > {
            messages.map((m, idx) => ( <
                div key = { idx }
                className = { `message ${m.sender === 'user' ? 'user' : 'bot'}` } >
                <
                div className = "bubble" >
                <
                strong > { m.sender === 'user' ? 'You' : 'AI' }: < /strong> <
                p > { m.text } < /p> <
                /div> <
                /div>
            ))
        } {
            loading && ( <
                div className = "message bot" >
                <
                div className = "bubble" >
                <
                strong > AI: < /strong> <
                p > Thinking about the best advice
                for your farm… < /p> <
                /div> <
                /div>
            )
        } <
        /div>

        <
        div className = "input-row" >
        <
        button type = "button"
        className = "mic-btn"
        onClick = { startVoiceInput }
        title = "Speak your question" >
        🎙
        <
        /button> <
        textarea value = { input }
        onChange = { e => setInput(e.target.value) }
        onKeyDown = { handleKeyPress }
        placeholder = "Describe your crop, soil type, problem, or question…"
        rows = { 2 }
        /> <
        button type = "button"
        className = "send-btn"
        onClick = { sendMessage }
        disabled = { loading } >
        { loading ? 'Sending…' : 'Send' } <
        /button> <
        /div> <
        /section> <
        /div> <
        /main>
    );
}