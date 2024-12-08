from flask import Flask, render_template, request, jsonify
import subprocess
from blockchain.deploy_contract import add_to_blockchain

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/detect', methods=['POST'])
def detect():
    text = request.form['text']
    # Call the C++ AI model
    result = subprocess.run(['./ai_model/model'], input=text, text=True, capture_output=True)
    category = "credible" if result.stdout.strip() == "1" else "inauthentic"
    if category == "credible":
        add_to_blockchain(text)
    return jsonify({'category': category})

if __name__ == '__main__':
    app.run(debug=True)
