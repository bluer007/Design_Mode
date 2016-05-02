/*
*	��Ԫģʽ	Դ�ļ�
*/


#include <iostream>
#include <map>
#include <vector>
#include "��Ԫģʽ.h"

using namespace std;

namespace xy
{			
	enum Color : int 
	{
		WHILE = 0,
		BLACK = 1
	};
	
	struct  Pos 
	{
		int x;
		int y;
		
		Pos(int ix = 0, int iy = 0) : x(ix), y(iy) {};

		//����<, ��Pos������Ϊmap��Ԫ��
		bool operator < (const Pos& other) const
		{
			if (this->x < other.x)
			{
				return true;
			}
			return false;
		};
	};

	//����, ����������ڲ����Ժ��ⲿ����
	class Piece
	{
	public:
		Piece(Color color) : m_color(color)
		{
				
		};

		//�������ԵĴ洢�ӿ�
		void SetPos(Pos pos)
		{
			this->m_pos = pos;
		};

		Color GetColor()
		{
			return m_color;
		}

		//ͨ���ýӿ�, ��pos����������ת�Ƶ�ChessBoard���д洢
		Pos GetPos()
		{
			return m_pos;
		}

	private:
		Pos m_pos;			//��������, ����Ԫģʽ��, �����մ洢��������(ChessBoard��)��
		Color m_color;		//��������, ����Ԫģʽ��, ��洢����������
	};

	//�̳�Piece, ����ʵ���Լ���Ҫ����������
	class GoChess : public Piece
	{
	public:
		GoChess(Color color) : Piece(color) {};
	};

	class ChessBoard
	{
	public:
		void Draw(Piece* piece)
		{
			if (WHILE == piece->GetColor())
			{
				cout << "this is while piece, pos is " << (piece->GetPos()).x 
					<< ":" << (piece->GetPos()).y << endl;
			}
			else
			{
				cout << "this is black piece, pos is " << (piece->GetPos()).x 
					<< ":" << (piece->GetPos()).y << endl;
			}
			m_chessboard.insert(pair<Pos, Piece*>(piece->GetPos(), piece));
		}

		void DrawAllPiece()
		{
			map<Pos, Piece*>::iterator ite;
			for (ite = m_chessboard.begin(); ite != m_chessboard.end(); ite++)
			{
				if (WHILE == ite->second->GetColor())
				{
				cout << ite->first.x << ":" << ite->first.y 
					<< " has a while piece" << endl;
				}
				else
				{
				cout << ite->first.x << ":" << ite->first.y 
					<< " has a black piece" << endl;
				}
			}
		}

 private:
		map<Pos, Piece*> m_chessboard;
	};

	class PieceFactory
	{
	public:
		PieceFactory() {}
		
		~PieceFactory()
		{
			for (vector<Piece*>::iterator ite = m_piece.begin(); ite != m_piece.end(); ite++)
			{
				delete *ite;
			}
			m_piece.clear();
		}

		Piece* GetPiece(Color color)
		{
			Piece* piece = nullptr;
			if (m_piece.empty())
			{
				piece = new GoChess(color);
				m_piece.push_back(piece);
			}
									
			for (vector<Piece*>::iterator ite = m_piece.begin(); ite != m_piece.end(); ite++)
			{
				if ((*ite)->GetColor() == color)
				{
					piece = *ite;
					break;
				}
			}

			if (!piece)
			{
				piece = new GoChess(color);
				m_piece.push_back(piece);
			}
			
			return piece;
		}

	private:
		vector<Piece*> m_piece;
	};

	void test_xy()
	{
		//�������е�Ч����, �����ഴ����"�߼�"�ϵ���������,
		//ʵ����ȴֻ����������, һ��"����",һ��"����"
		//��ɫ��Ϣ��Ϊ��������(��������), �洢��Piece��
		//λ����Ϣ��Ϊ��������(�仯����), �洢��ChessBoard����
		//�����˴��������ظ��Ķ���--����

		cout << "\n----��Ԫģʽ----\n";
		PieceFactory* factory = new PieceFactory();
		ChessBoard* chessboard = new ChessBoard();

		Piece* piece = factory->GetPiece(WHILE); 
		piece->SetPos(Pos(1, 2));
		chessboard->Draw(piece);

		piece = factory->GetPiece(BLACK);
		piece->SetPos(Pos(3, 4));
		chessboard->Draw(piece);
		
		piece = factory->GetPiece(WHILE); 
		piece->SetPos(Pos(5, 6));
		chessboard->Draw(piece);
	
		cout << endl << "start draw all pieces..." << endl;
		chessboard->DrawAllPiece();

		delete factory;
		delete chessboard;
	};
};
