import express from 'express';
import cors from 'cors';
import dotenv from 'dotenv';

dotenv.config();

const app = express();
const PORT = process.env.PORT || 5000;

app.use(cors());
app.use(express.json());

app.get('/', (req, res) => {
    res.send('Smart Agriculture AI Backend is running');
});

app.post('/api/chat', async(req, res) => {
    const { message, language } = req.body;

    if (!message) {
        return res.status(400).json({ error: 'Message is required' });
    }

    try {
        const apiKey = process.env.OPENAI_API_KEY;
        if (!apiKey) {
            return res.status(500).json({ error: 'OPENAI_API_KEY is not set in .env' });
        }

        const targetLanguage = language || 'English';

        const systemPrompt = `
You are an AI agriculture assistant for Indian farmers.
- Give practical, simple answers about crops, soil, weather, fertilizers, pests, irrigation, and market price ideas.
- Assume small to medium Indian farms, low-cost solutions first.
- Reply in ${targetLanguage}.
- If user language is Hindi or Marathi, answer fully in that language.
- Keep answers short and to the point unless user asks for detail.
`;

        const response = await fetch('https://api.openai.com/v1/chat/completions', {
            method: 'POST',
            headers: {
                Authorization: `Bearer ${apiKey}`,
                'Content-Type': 'application/json'
            },
            body: JSON.stringify({
                model: 'gpt-4o-mini',
                messages: [
                    { role: 'system', content: systemPrompt },
                    { role: 'user', content: message }
                ],
                temperature: 0.4
            })
        });

        if (!response.ok) {
            const errorText = await response.text();
            console.error('OpenAI error:', errorText);
            return res.status(500).json({ error: 'AI provider error' });
        }

        const data = await response.json();
        const reply =
            data.choices ? .[0] ? .message ? .content ||
            'माफ़ कीजिए, अभी उत्तर देने में समस्या हो रही है। बाद में पुनः प्रयास करें।';

        res.json({ reply });
    } catch (err) {
        console.error('Server error:', err);
        res.status(500).json({ error: 'Server error' });
    }
});

app.listen(PORT, () => {
    console.log(`Smart Agriculture AI backend running on http://localhost:${PORT}`);
});