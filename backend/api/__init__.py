from app import create_app, db
from app.api import api as api_blueprint

def create_app():
    app = Flask(__name__)
    app.config.from_object(Config)
    db.init_app(app)

    app.register_blueprint(api_blueprint, url_prefix='/api')

    return app
